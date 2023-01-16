program ADD_PROG{                               // program name
    version ADD_VERS{                           // version name
        int PROC_1(int) = 1;                    // procedure 1(accepts int returns int)                 
        float PROC_2(int, string x<>) = 2;      // procedure 2(accepts int and string returns float)
        string PROC_3(int) = 3;                 // procedure 3(accepts int returns string)
    } = 1;                                      // version number
} = 0x20000001;                                 // program number