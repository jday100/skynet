int strlen(const char* value)
{
    int result  = 0;

    do{
        if(value[result++] == '\0'){
            break;
        }
    }while(true);
    return result;
}
