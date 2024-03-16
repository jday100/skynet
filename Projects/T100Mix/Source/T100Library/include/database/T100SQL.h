#ifndef T100SQL_H
#define T100SQL_H

#include "T100String.h"


class T100SQL
{
    public:
        T100SQL();
        virtual ~T100SQL();

        static T100String       CREATE(T100String);
        static T100String       DROP(T100String);
        static T100String       ALTER(T100String);

        static T100String       SELECT(T100String);
        static T100String       INSERT(T100String);
        static T100String       DELETE(T100String);
        static T100String       UPDATE(T100String);

        ///Join
        static T100String       INNER(T100String);
        static T100String       LEFT(T100String);
        static T100String       RIGHT(T100String);

        ///
        static T100String       PREFIX(T100String, T100String);
        static T100String       ALIAS(T100String, T100String);

        ///
        static T100String       NAME(T100String);

        static T100String       COUNT(T100String);
        static T100String       AS(T100String, T100String);
        static T100String       SET(T100String);
        static T100String       ASSIGN(T100String, T100String);

        static T100String       FIELDS(T100String);
        static T100String       VALUES(T100String);

        static T100String       FROM(T100String);
        static T100String       WHERE(T100String);
        static T100String       ORDER(T100String);
        static T100String       DESC(T100String);
        static T100String       LIMIT(T100String);
        static T100String       OFFSET(T100String);
        static T100String       MATCH(T100String);
        static T100String       AGAINST(T100String);

        ///
        static T100String       AND(T100String, T100String);
        static T100String       OR(T100String, T100String);
        static T100String       NOT(T100String);

        ///
        static T100String       IN(T100String, T100String);
        static T100String       EQUAL(T100String, T100String);
        static T100String       GREATER_THEN(T100String, T100String);
        static T100String       LESS_THEN(T100String, T100String);
        static T100String       GREATER_EQUAL(T100String, T100String);
        static T100String       LESS_EQUAL(T100String, T100String);

        static T100String       STRING(T100String);


    protected:

    private:
};

#endif // T100SQL_H
