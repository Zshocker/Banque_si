#pragma once
#include "Devise.h"
namespace Banque {
    class MAD : public Devise
    {
        const static double RatioToDollar;
        const static double RatioToEuro;
    public:
        MAD(double Val);
        MAD(const MAD& Val);
        void afficher()const override;
        Devise* Clone() const;
        Dollar* ConverToDollar()const;
        MAD* ConverToMAD()const;
        Euro* ConverToEuro()const;
    };
}
