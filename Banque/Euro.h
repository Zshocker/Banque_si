#pragma once
#include "Devise.h"
namespace Banque {
    class Euro :
        public Devise
    {
        const static double RatioToDollar;
        const static double RatioToMAD;
    public:
        Euro(double Val);
        Euro(const Euro& Val);
        void afficher()const override;
        Devise* Clone() const;
        Dollar* ConverToDollar()const;
        MAD* ConverToMAD()const;
        Euro* ConverToEuro()const;
    };
}
