#include <stdio.h>

typedef struct
{
    int i;
    int f;
    int result;
}evento;

int main()
{
    evento d, h, m, s;
    //Lendo Errado
    scanf("Dia %d", &d.i);
    scanf("%d : %d : %d\n", &h.i, &m.i, &s.i);
    scanf("Dia %d", &d.f);
    scanf("%d : %d : %d\n", &h.f, &m.f, &s.f);
    
    d.result = d.f - d.i;
    h.result = h.f - h.i;
    m.result = m.f - m.i;
    s.result = s.f - s.i;

    if(s.result < 0){
        s.result += 60;
        m.result--;
    }

    if(m.result < 0){
        m.result += 60;
        h.i--;
    }
    
    if(h.i < 0){
        h.i += 24;
        d.result--;
    }

    printf("%d dia(s)\n", d.result);
    printf("%d hora(s)\n", h.i);
    printf("%d minuto(s)\n", m.result);
    printf("%d segundo(s)\n", s.result);

    return 0;
}