#include "T100ScannerTools.h"

#include "compiler/classifier/T100ByteClassifier.h"

namespace T100LIBRARY{

T100ScannerTools::T100ScannerTools() :
    T100Class()
{
    //ctor
}

T100ScannerTools::~T100ScannerTools()
{
    //dtor
}

T100BOOL T100ScannerTools::CreateScanner(T100SourceScanner*& sScanner, T100FileScanner*& fScanner)
{
    T100BOOL                    result;
    T100SourceScanner*          sourceScanner           = T100NULL;
    T100FunctionScanner*        functionScanner         = T100NULL;
    T100SegmentScanner*         segmentScanner          = T100NULL;
    T100SentenceScanner*        sentenceScanner         = T100NULL;
    T100KeywordScanner*         keywordScanner          = T100NULL;
    T100StringScanner*          stringScanner           = T100NULL;
    T100CharScanner*            charScanner             = T100NULL;
    T100ByteScanner*            byteScanner             = T100NULL;
    T100BufferScanner*          bufferScanner           = T100NULL;
    T100FileScanner*            fileScanner             = T100NULL;

    T100ByteClassifier*         byteClassifier          = T100NULL;

    sourceScanner           = T100NEW T100SourceScanner();

    if(!sourceScanner){
        return T100FALSE;
    }

    functionScanner         = T100NEW T100FunctionScanner();

    if(!functionScanner){
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    sourceScanner->SetSource(functionScanner);

    segmentScanner          = T100NEW T100SegmentScanner();

    if(!segmentScanner){
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    functionScanner->SetSource(segmentScanner);

    sentenceScanner         = T100NEW T100SentenceScanner();

    if(!sentenceScanner){
        T100SAFE_DELETE(segmentScanner);
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    segmentScanner->SetSource(sentenceScanner);

    keywordScanner          = T100NEW T100KeywordScanner();

    if(!keywordScanner){
        T100SAFE_DELETE(sentenceScanner);
        T100SAFE_DELETE(segmentScanner);
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    sentenceScanner->SetSource(keywordScanner);

    stringScanner           = T100NEW T100StringScanner();

    if(!stringScanner){
        T100SAFE_DELETE(keywordScanner);
        T100SAFE_DELETE(sentenceScanner);
        T100SAFE_DELETE(segmentScanner);
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    keywordScanner->SetSource(stringScanner);

    charScanner             = T100NEW T100CharScanner();

    if(!charScanner){
        T100SAFE_DELETE(stringScanner);
        T100SAFE_DELETE(keywordScanner);
        T100SAFE_DELETE(sentenceScanner);
        T100SAFE_DELETE(segmentScanner);
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    stringScanner->SetSource(charScanner);

    byteScanner             = T100NEW T100ByteScanner();

    if(!byteScanner){
        T100SAFE_DELETE(charScanner);
        T100SAFE_DELETE(stringScanner);
        T100SAFE_DELETE(keywordScanner);
        T100SAFE_DELETE(sentenceScanner);
        T100SAFE_DELETE(segmentScanner);
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    byteClassifier          = T100NEW T100ByteClassifier();

    if(!byteClassifier){
        T100SAFE_DELETE(byteScanner);
        T100SAFE_DELETE(charScanner);
        T100SAFE_DELETE(stringScanner);
        T100SAFE_DELETE(keywordScanner);
        T100SAFE_DELETE(sentenceScanner);
        T100SAFE_DELETE(segmentScanner);
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    byteScanner->SetClassifier(byteClassifier);
    charScanner->SetSource(byteScanner);

    bufferScanner           = T100NEW T100BufferScanner();

    if(!bufferScanner){
        T100SAFE_DELETE(byteScanner);
        T100SAFE_DELETE(charScanner);
        T100SAFE_DELETE(stringScanner);
        T100SAFE_DELETE(keywordScanner);
        T100SAFE_DELETE(sentenceScanner);
        T100SAFE_DELETE(segmentScanner);
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    byteScanner->SetSource(bufferScanner);

    fileScanner             = T100NEW T100FileScanner();

    if(!fileScanner){
        T100SAFE_DELETE(bufferScanner);
        T100SAFE_DELETE(byteScanner);
        T100SAFE_DELETE(charScanner);
        T100SAFE_DELETE(stringScanner);
        T100SAFE_DELETE(keywordScanner);
        T100SAFE_DELETE(sentenceScanner);
        T100SAFE_DELETE(segmentScanner);
        T100SAFE_DELETE(functionScanner);
        T100SAFE_DELETE(sourceScanner);
        return T100FALSE;
    }

    bufferScanner->SetSource(fileScanner);

    sScanner        = sourceScanner;
    fScanner        = fileScanner;

    return T100TRUE;
}

}
