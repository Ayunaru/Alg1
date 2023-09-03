/*Gladstone está desenvolvendo um jogo simples de RPG em que há batalhas, os quais são por turnos, onde, em cada luta, os jogadores se revezam em cada ataque. Cada personagem, além do nome (string), tem os seguintes atributos representados por números inteiros: energia, defesa e força. Em cada ataque, a energia do personagem que está sofrendo o golpe é reduzida. O dano (redução de energia) é dado pela subtração entre o atributo de força (F) do atacante e o atributo de defesa do personagem atacado, o qual pode ter redução de energia. Caso a diferença entre força (atacante) e defesa (atacado) seja menor igual a zero, o dano será de 1 ponto. Se o dano resultar em energia negativa, o valor da mesma para o personagem derrotado deverá ser "0". Em cada batalha, o perdedor será o personagem que tiver a energia zerada ou que tiver o menor valor de energia. Também, poderá ocorrer empate. É importante ressaltar que o personagem com energia zerada não pode mais atacar!

Implemente uma função que receba duas variáveis referentes aos personagens e um número inteiro que represente a quantidade de turnos, onde o primeiro personagem fornecido como parâmetro começa o ataque. Ao final, a função deverá imprimir o resultado, indicando o nome personagem vencedor ou se houve empate.

Input Format

Nas duas primeiras linhas, devem ler lidos os dados dos personagens. "nome (vetor de char) energia (int) defesa (int), força (int)".

Na linha seguinte, deve ser lida a quantidade de rodadas que deverá ter a batalha.

Constraints

.

Output Format

Na primeira e segunda linha, imprimir o nome e a energia restante do primeiro e do segundo personagem, após a execução das rodadas de ataques.

Na terceira lunha, imprimir o nome do personagem vencedor ou "empate", caso os personagens tiverem a mesma quantidade de energia (neste exercício não levando em conta que os personagens possam iniciar uma batalha com diferentes valores de energia).*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[30];
    int energy, defense, attack;
} rpg;

void battle(rpg *person1, rpg *person2, int turns)
{
    for (int i = 0; i < turns; i++)
    {
        int aux = person1->attack - person2->defense;

        if (aux <= 0)
        {
            person2->energy--;
        }
        else
        {
            person2->energy = person2->energy - aux;
        }

        if (person2->energy <= 0)
        {
            person2->energy = 0;
            printf("Status Winner: %s   Energy: %d \n", person1->name, person1->energy);
            printf("Status Loser: %s Energy: %d \n", person2->name, person2->energy);
            break;
        }

        aux = person2->attack - person1->defense;

        if (aux <= 0)
        {
            person1->energy--;
        }
        else
        {
            person1->energy = person1->energy - aux;
        }

        if (person1->energy <= 0)
        {
            person1->energy = 0;
            printf("Status Winner: %s   Energy: %d \n", person2->name, person2->energy);
            printf("Status Loser: %s Energy: %d \n", person1->name, person1->energy);
            break;
        }
    }

    if (person1->energy > person2->energy)
    {
        printf("Player %s wins!\n", person1->name);
    }
    else if (person2->energy > person1->energy)
    {
        printf("Player %s wins!\n", person2->name);
    }
    else
    {
        printf("It's a draw!\n");
    }
}

int main()
{
    rpg person1, person2;
    int turns;

    printf("Enter the data for Player 1:\n");
    scanf("%s %d %d %d", person1.name, &person1.energy, &person1.defense, &person1.attack);

    printf("Enter the data for Player 2:\n");
    scanf("%s %d %d %d", person2.name, &person2.energy, &person2.defense, &person2.attack);

    printf("Enter the number of turns: ");
    scanf("%d", &turns);

    printf("\nPlayer One database:\n");
    printf("Name: %s\nEnergy: %d\nDefense: %d\nAttack: %d\n", person1.name, person1.energy, person1.defense, person1.attack);

    printf("\nPlayer Two database:\n");
    printf("Name: %s\nEnergy: %d\nDefense: %d\nAttack: %d\n", person2.name, person2.energy, person2.defense, person2.attack);

    battle(&person1, &person2, turns);

    return 0;
}
