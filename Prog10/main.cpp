#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void clearScreen () {
    cout << "\033[H\033[2J";
}

void couleur (const unsigned & coul) {
    cout << "\033[" << coul <<"m";
}

typedef vector <unsigned> CVLine; // un type représentant une ligne de la grille
typedef vector <CVLine> CMat; // un type représentant la grille
struct maPosition {
    unsigned abs;
    unsigned ord;
}; // une position dans la grille


void InitGrid (CMat & Grid, unsigned Size){
    unsigned val = 4;
    Grid.resize(Size, CVLine (Size, rand()%(val+1)));
    for(unsigned i=0;i<4;i=i+1){
        for(unsigned j=0;j<4;j=j+1){
            Grid[i][j]=rand()%val+1;
        }
    }
}

void  DisplayGrid (const CMat & Grid){
    clearScreen();
    // const unsigned KReset   (0);
    // const unsigned KNoir    (30);
    // const unsigned KRouge   (31);
    // const unsigned KVert    (32);
    // const unsigned KJaune   (33);
    // const unsigned KBleu    (34);
    // const unsigned KMAgenta (35);
    // const unsigned KCyan    (36);
    for(const CVLine & uneLigne : Grid){
        for(const unsigned & cel : uneLigne) cout << setw(3) << cel;
        cout << endl;
    }
}

char SaisieDirection(){
    cout << "Saisir une direction (Z,Q,S,D)" << endl;
    char Direction;
    cin >> Direction;
    return Direction;
}

void MakeAMove (CMat & Grid, const maPosition & Pos, char Direction){
    unsigned tmp = 0;
    maPosition posarriv;
    posarriv.abs=Pos.abs;
    posarriv.ord=Pos.ord;
    if(Direction != 'Z' && Direction != 'Q' && Direction != 'S' && Direction != 'D' && Direction != 'z' && Direction != 'q' && Direction != 's' && Direction != 'd')
        cout << "Mauvaise saisie";
    if(Direction == 'Z' || Direction == 'z'){
        if(Pos.abs==0){
            posarriv.abs=4;
            tmp=Grid[Pos.abs][Pos.ord];
            Grid[Pos.abs][Pos.ord]=Grid[posarriv.abs][posarriv.ord];
            Grid[posarriv.abs][posarriv.ord]=tmp;
        }
        else{
            posarriv.ord=Pos.ord-1;
            tmp=Grid[Pos.abs][Pos.ord];
            Grid[Pos.abs][Pos.ord]=Grid[posarriv.abs][posarriv.ord];
            Grid[posarriv.abs][posarriv.ord]=tmp;
        }
    }
    if(Direction == 'Q' || Direction == 'q'){
        if(Pos.ord==0){
            posarriv.ord=4;
            tmp=Grid[Pos.abs][Pos.ord];
            Grid[Pos.abs][Pos.ord]=Grid[posarriv.abs][posarriv.ord];
            Grid[posarriv.abs][posarriv.ord]=tmp;
        }
        else{
            posarriv.abs=Pos.abs-1;
            tmp=Grid[Pos.abs][Pos.ord];
            Grid[Pos.abs][Pos.ord]=Grid[posarriv.abs][posarriv.ord];
            Grid[posarriv.abs][posarriv.ord]=tmp;
        }
    }
    if(Direction == 'S' || Direction == 's'){
        if(Pos.abs==4){
            posarriv.abs=0;
            tmp=Grid[Pos.abs][Pos.ord];
            Grid[Pos.abs][Pos.ord]=Grid[posarriv.abs][posarriv.ord];
            Grid[posarriv.abs][posarriv.ord]=tmp;
        }
        else{
            posarriv.abs=Pos.abs+1;
            tmp=Grid[Pos.abs][Pos.ord];
            Grid[Pos.abs][Pos.ord]=Grid[posarriv.abs][posarriv.ord];
            Grid[posarriv.abs][posarriv.ord]=tmp;
        }
    }
    if(Direction == 'D' || Direction == 'd'){
        if(Pos.ord==4){
            posarriv.ord=0;
            tmp=Grid[Pos.abs][Pos.ord];
            Grid[Pos.abs][Pos.ord]=Grid[posarriv.abs][posarriv.ord];
            Grid[posarriv.abs][posarriv.ord]=tmp;
        }
        else{
            posarriv.ord=Pos.ord+1;
            tmp=Grid[Pos.abs][Pos.ord];
            Grid[Pos.abs][Pos.ord]=Grid[posarriv.abs][posarriv.ord];
            Grid[posarriv.abs][posarriv.ord]=tmp;
        }
    }
    DisplayGrid(Grid);
}

bool AtLeastThreeInAColumn (const CMat & Grid, maPosition & Pos, unsigned & HowMany);

int main()
{
    // clearScreen();
    // couleur(KRouge);
    // cout << "Rouge" << endl;
    // couleur(KVert);
    // cout << "Vert" << endl;
    // couleur(KReset);
    // cout << "Retour à la normale" << endl;
    CMat Grid;
    InitGrid(Grid, 5);
    DisplayGrid(Grid);
    maPosition Pos;
    cout << "Saissisez la coordonnée d'abscisse du chiffre que vous souhaitez déplacer" << endl;
    cin >> Pos.abs;
    cout << "Saissisez la coordonnée d'ordonnée du chiffre que vous souhaitez déplacer" << endl;
    cin >> Pos.ord;
    cout << "Chiffre :" << endl;
    cout << Grid[Pos.abs][Pos.ord];
    char Direction=SaisieDirection();
    MakeAMove(Grid,Pos,Direction);
    return 0;

}
