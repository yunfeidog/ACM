#include "stdio.h"



int main() {
//    输入的一行包含6个数a,b,c,d,,f,分别为角色的攻击力，技能倍率，伤害提高值，增伤比例，暴击伤
//害，怪物抗性。
    double a,b,c,d,e,f;
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
    double res=0;
    res=(a*b+c)*(1+d)*(1+e)*0.478*(1-f);
    printf("%.2lf",res);

    return 0;
}
