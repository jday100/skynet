#include "T100Unzip.h"

#include <wx/zipstrm.h>
#include <wx/wfstream.h>

T100Unzip::T100Unzip()
{
    //ctor
}

T100Unzip::~T100Unzip()
{
    //dtor
}

T100BOOL T100Unzip::Uncompress(const wxString& source, const wxString& target)
{
    wxFileInputStream       input(source);
    wxZipInputStream        unzip(input);

    if(!unzip.IsOk()){
        return T100FALSE;
    }

    wxString    sep     = wxFileName::GetPathSeparator();
    wxString    dir     = target.EndsWith(sep) ? target : target + sep;

    wxZipEntry*     entry   = T100NULL;

    while((entry = unzip.GetNextEntry()) != T100NULL){
        wxFileName      name(entry->GetName());
        wxString        path = dir + name.GetFullPath();

        if(entry->IsDir()){
            wxFileName::Mkdir(path, wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL);
        }else{
            wxFFileOutputStream     file(path);

            if(file.IsOk()){
                if(unzip.Read(file).GetLastError() == wxSTREAM_EOF){
                    file.Close();
                    T100SAFE_DELETE(entry);
                    continue;
                }
            }
            T100SAFE_DELETE(entry);
            return T100FALSE;
        }
    }
    return T100TRUE;
}
