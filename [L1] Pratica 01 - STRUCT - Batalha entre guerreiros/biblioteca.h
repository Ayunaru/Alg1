
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
        int atk, def, vida, car, id;
} Guerreiro;

int rolaDados() 
{
        int v[3];
            int valor = 0;
                for (int i = 0; i < 3; i++) {
                            v[i] = rand() % 6 + 1;
                }
                    valor = v[0] + v[1] + v[2];
                        return valor;
}

void criaGuerreiro(Guerreiro *guerreiro) 
{
        guerreiro->atk = rolaDados();
            guerreiro->def = rolaDados();
                guerreiro->car = rolaDados();
                    guerreiro->vida = rolaDados() + rolaDados() + rolaDados();
}

void bonus(Guerreiro *x) 
{
        if (x->car == 18) {
                    x->atk += 3;
        } else if (x->car == 17 || x->car == 16) {
                    x->atk += 2;
        } else if (x->car == 14 || x->car == 15) {
                    x->atk += 1;
        } else if (x->car == 6 || x->car == 7) {
                    x->atk -= 1;
        } else if (x->car == 4 || x->car == 5) {
                    x->atk -= 2;
        } else if (x->car == 3) {
                    x->atk -= 3;
        }
}

void ataca(Guerreiro *atacante, Guerreiro *defensor) 
{
        int golpe = rolaDados() + atacante->atk;
            int escudo = rolaDados() + defensor->def;
                int dano = golpe - escudo;
                    if (dano > 0) {
                                defensor->vida -= dano;
                                        if (defensor->vida < 0)
                                                    defensor->vida = 0;
                    }
}

#endif