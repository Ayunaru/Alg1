
#include "biblioteca.h"

int main() 
{
        srand(time(NULL));
        
            Guerreiro guerreiro1, guerreiro2;
            guerreiro1.id = 1;
            guerreiro2.id = 2;
                    
            criaGuerreiro(&guerreiro1);
            criaGuerreiro(&guerreiro2);
                            
            while (guerreiro1.vida > 0 && guerreiro2.vida > 0) 
            {
             ataca(&guerreiro1, &guerreiro2);
            //printf("Guerreiro 1 ataca Guerreiro 2 - PV Guerreiro 2: %d", guerreiro2.vida);
            if (guerreiro2.vida <= 0)
                break;
            ataca(&guerreiro2, &guerreiro1);
            //printf("Guerreiro 2 ataca Guerreiro 1 - PV Guerreiro 1: %d", guerreiro1.vida);
            }
            if (guerreiro1.vida > guerreiro2.vida)
                printf("%d", guerreiro1.id);
            else
                printf("%d", guerreiro2.id);
                return 0;
}