#pragma once
#include "Transaction.h"

namespace Banque {
    class OperationV :public Transaction
    {
    public:
        OperationV(Devise*E,Compte*c);
        void Print()const;
    private:
        static string libel;
    };
}
