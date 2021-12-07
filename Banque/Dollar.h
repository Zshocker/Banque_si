#pragma once
#include "Devise.h"
namespace Banque {
    class Dollar :public Devise
    {
        const static double RatioToMAD;
        const static double RatioToEuro;
    public:
        Dollar(double Val);
        Dollar(const Dollar& Val);
        void afficher()const override;
        Devise* Clone() const;
        Dollar* ConverToDollar()const;
        MAD* ConverToMAD()const;
        Euro* ConverToEuro()const;
    };
}
