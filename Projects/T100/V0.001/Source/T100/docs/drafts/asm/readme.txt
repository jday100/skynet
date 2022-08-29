share.txt

DATA    SHARE   LOCATION=1114112
    share_value                         INTEGER
END 

master.txt

IMPORT      "share.txt"

MODE    REAL    TINY

DATA
    value                               INTEGER     1
END

CODE
    MOVE    share_value                 value
    //
    JUMP    {1114112:0}
END


IMPORT      "share.txt"

MODE    REAL    TINY

DATA
    value                               INTEGER
END

CODE
    MOVE    value                       share_value
    //
    HALT
END


CODE 				DATA

CBR+COR				CBR+OFFSET


CODE				DATA 

CBR+CSR+COR			CBR+CDR+OFFSET



