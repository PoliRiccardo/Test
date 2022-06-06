#include <iostream>
using namespace std;
const int materie_max = 5 , alunni_max = 100;
struct Studente  {
    string nome;
    string cognome;
    int classe;
    int id;
};
struct Materia {
    string nome;
    float voto;
};
struct Registro {
    Studente studente;
    Materia materia[materie_max];
};

void menu() {
    cout << "1) Caricare i dati anagrafici dello studente " << endl;
    cout << "2) Dato l’ID di uno studente caricare i voti finali riportati a fine anno in ogni singola materia " << endl;
    cout << "3) Data una particolare materia cercare gli studenti che hanno un voto compreso tra 6 e 8 e visualizzare il loro cognome e nome, la classe frequentata, il voto e le materie in cui hanno riportato questo voto " << endl;
    cout << "4) Dato un particolare ID  visualizzare il voto piu’ alto che ha preso e in quale materie è stato ottenuto " << endl;
    cout << "5) Ricercare lo studente che ha ottenuto il voto più alto in assoluto e visualizzare quale voto è e in quale materia " << endl;
    cout << "6) Ricercare lo studente che ha ottenuto il voto più basso in assoluto e visualizzare quale voto è e in quale materia " << endl;
    cout << "7) Ricercare gli studenti bocciati, ossia quelli che hanno almeno 2 insufficienze (voto minore di 6) e visualizzarne cognome, nome e classe " << endl;
    cout << "8) Ricercare fra gli studenti delle classi terze quello che ha avuto la media più alta e visualizzarne cognome, nome, classe e a quanto ammonta questa media " << endl;
    cout << "9) Dato un id stampare dei dati dello studente con nome, cognome, classe, voti finali in ogni materia e media " << endl;
    cout << "0) esci " << endl;
}
void inserimento_alunno (Registro &a){
    cout << "inserisci il nome: " << endl;
    cin >> a.studente.nome;
    cout << "inserisci il cognome: " << endl;
    cin >> a.studente.cognome;
    cout << "inserisci la classe : " << endl;
    cin >> a.studente.classe;
    cout << "inserisci l'id : " << endl;
    cin >> a.studente.id;
}
void inserimento_voto (Registro &a ){
    a.materia[0].nome="italiano";
    a.materia[1].nome="matematica";
    a.materia[2].nome="inglese";
    a.materia[3].nome="scienze";
    a.materia[4].nome="disegno";
    cout << "inserisci il voto finale di italiano : " << endl;
    cin >> a.materia[0].voto;
    cout << "inserisci il voto finale di matematica : " << endl;
    cin >> a.materia[1].voto;
    cout << "inserisci il voto finale di inglese : " << endl;
    cin >> a.materia[2].voto;
    cout << "inserisci il voto finale di scienze : " << endl;
    cin >> a.materia[3].voto;
    cout << "inserisci il voto finale di disegno : " << endl;
    cin >> a.materia[4].voto;

}
void stampa_alunno (Registro a[] , int temp ){
    float media=(a[temp].materia[0].voto+a[temp].materia[1].voto+a[temp].materia[2].voto+a[temp].materia[3].voto+a[temp].materia[4].voto)/5;
    cout<<"il nome dello studente e': " <<a[temp].studente.nome<<endl;
    cout<<"il conome dello studente e': " <<a[temp].studente.cognome<<endl;
    cout<<"la classe dello studente e': " <<a[temp].studente.classe<<endl;
    cout<<"il suo voto finale in italiano e': " <<a[temp].materia[0].voto<<endl;
    cout<<"il suo voto finale in matematica e': " <<a[temp].materia[1].voto<<endl;
    cout<<"il suo voto finale in inglese e': " <<a[temp].materia[2].voto<<endl;
    cout<<"il suo voto finale in scienze e': " <<a[temp].materia[3].voto<<endl;
    cout<<"il suo voto finale in disegno e': " <<a[temp].materia[4].voto<<endl;
    cout<<"la sua media : " <<media<<endl;
}
void ricerca_media(Registro a[] , int n , string disciplina  ){
    int numerazione_materia=6;
    for (int i = 0; i < 5; ++i) {
        if (a[0].materia[i].nome==disciplina) numerazione_materia=i;
    }
    if (numerazione_materia!=6){
        for (int i = 0; i < n; ++i) {
            if (a[i].materia[numerazione_materia].voto>=6 && a[i].materia[numerazione_materia].voto<=8){
                cout<<"il nome dello studente e': " <<a[i].studente.nome<<endl;
                cout<<"il conome dello studente e': " <<a[i].studente.cognome<<endl;
                cout<<"la classe dello studente e': " <<a[i].studente.classe<<endl;
                cout<<"il voto dello studente e' : " << a[i].materia[numerazione_materia].voto<<endl;
            }
        }
    }
    else cout<<"materia non trovata"<<endl;
}
void ricerca_voto_piu_alto(Registro a[] , int n){
    float voto_max = a[n].materia[0].voto;
    string nome_materia=a[n].materia[0].nome;
    for (int i = 1; i < 5; ++i) {

        if (a[n].materia[i].voto>voto_max) {
            nome_materia="";
            voto_max=a[n].materia[i].voto;
            nome_materia=a[n].materia[i].nome;
        }

    }
    cout<<"la materia in cui  ha preso il voto massimo e' : "<<nome_materia<<endl;
    cout<<"Il voto e' : "<<voto_max<<endl;
}
void voto_piu_alto_assoluto(Registro a[] , int n ){
    float voto_max = a[0].materia[0].voto;
    string nome_materia=a[0].materia[0].nome;
    string nome_alunno=a[0].studente.nome;
    string cognome_alunno=a[0].studente.cognome;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (a[i].materia[j].voto>=voto_max){
                nome_materia="";
                nome_alunno="";
                cognome_alunno="";
                voto_max=a[i].materia[j].voto;
                nome_materia=a[i].materia[j].nome;
                nome_alunno=a[i].studente.nome;
                cognome_alunno=a[i].studente.cognome;

            }
        }
    }
    cout<<"il voto piu' alto e' :"<<voto_max <<" ed e' stato preso in "<<nome_materia<<" l'alunno e' "<<nome_alunno <<" "<<cognome_alunno <<endl;
}
void voto_piu_basso_assoluto(Registro a[] , int n ){
    float voto_min = a[0].materia[0].voto;
    string nome_materia=a[0].materia[0].nome;
    string nome_alunno=a[0].studente.nome;
    string cognome_alunno=a[0].studente.cognome;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (a[i].materia[j].voto<=voto_min){
                nome_materia="";
                nome_alunno="";
                cognome_alunno="";
                voto_min=a[i].materia[j].voto;
                nome_materia=a[i].materia[j].nome;
                nome_alunno=a[i].studente.nome;
                cognome_alunno=a[i].studente.cognome;

            }
        }
    }
    cout<<"il voto piu' basso e' :"<<voto_min <<" ed e' stato preso in "<<nome_materia<<" l'alunno e' "<<nome_alunno <<" "<<cognome_alunno <<endl;
}
void studenti_bocciati(Registro a[] , int n ){
    int cont=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (a[i].materia[j].voto<6) cont++;
        }
        if (cont>=2){
            cout<<"lo studente "<<a[i].studente.nome << " " << a[i].studente.cognome << "classe : " <<a[i].studente.classe <<" "<<"e' bocciato " <<endl;
        cont=0;
    }

    }
}
void media_piu_elevata(Registro a[] , int n ){
    float media_max=(a[0].materia[0].voto+a[0].materia[1].voto+a[0].materia[2].voto+a[0].materia[3].voto+a[0].materia[4].voto)/5;
    float media=0;
    string nome_alunno=a[0].studente.nome;
    string cognome_alunno=a[0].studente.cognome;
    int cont=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (a[i].studente.classe==3){
                cont++;
                media+=a[i].materia[j].voto;
                if (cont==5) {
                    media/=5;
                    if (media>media_max){
                        media_max=media;
                        cognome_alunno=a[i].studente.cognome;
                        nome_alunno=a[i].studente.nome;
                    }
                }
            }

        }
        cont=0;
        media=0;
    }
    cout<<"la media piu' alto e' :"<<media_max <<" l'alunno e' "<<nome_alunno <<" "<<cognome_alunno <<endl;
}
int main() {
    Registro registro_online[alunni_max];
    int scelta=-1 , alunni_inseriti = 0 , id ,temp=-1;
    string disciplina;
    menu();
    while (scelta != 0){
        cout << "inserisci la scelta " << endl;
        cin >> scelta;
        switch (scelta) {
            case 1:
                inserimento_alunno(registro_online[alunni_inseriti]);
                alunni_inseriti++;
                break;
            case 2:

                cout<<"inserisci l'id dello studente :"<<endl;
                cin>>id;
                for (int i = 0; i < alunni_inseriti; ++i) {
                    if (registro_online[i].studente.id==id) temp=i;
                }
                if (temp==-1) cout<<"id errato " <<endl;
                else inserimento_voto(registro_online[temp]);
                temp=-1;
                break;
            case 3:
                cout<<"inserisci la materia, in minuscolo : "<<endl;
                cin>>disciplina;
                ricerca_media(registro_online , alunni_inseriti , disciplina);
                break;
            case 4:
                cout<<"inserisci l'id dello studente :"<<endl;
                cin>>id;
                for (int i = 0; i < alunni_inseriti; ++i) {
                    if (registro_online[i].studente.id==id) temp=i;
                }
                if (temp==-1) cout<<"id errato " <<endl;
                else ricerca_voto_piu_alto(registro_online , temp );
                temp=-1;
                break;

            case 5:
                voto_piu_alto_assoluto(registro_online , alunni_inseriti);
                break;
            case 6:
                voto_piu_basso_assoluto(registro_online,alunni_inseriti);
                break;
            case 7:
                studenti_bocciati(registro_online , alunni_inseriti);
                break;
            case 8:
                media_piu_elevata(registro_online ,  alunni_inseriti);
                break;
            case 9:
                cout<<"inserisci l'id dell'alunno:"<<endl;
                cin>>id;
                for (int i = 0; i < alunni_inseriti; ++i) {
                    if (registro_online[i].studente.id==id) temp=i;
                }
                if (temp==-1) cout<<"id errato "<<endl;
                else stampa_alunno(registro_online ,temp );
                temp=-1;
                break;
            case 0:
                scelta=0;
                break;
            default:
                cout << "hai inserito una opzione non valida" << endl;
                break;

        }
    }
    return 0;
}
