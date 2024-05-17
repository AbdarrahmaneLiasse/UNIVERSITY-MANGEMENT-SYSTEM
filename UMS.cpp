#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
//Declaration des classes

class NiveauEtude{
    int nE;
    public:
    NiveauEtude(int Ne):nE(Ne){}
    int getNE(){
        return nE;
    }
};

class Filiere{
    string nomFil;
    int NE;
    public:
    Filiere():nomFil(""),NE(0){}
    Filiere(string nf,NiveauEtude &ne):nomFil(nf),NE(ne.getNE()){}
    string getNF(){return nomFil;}
    int getNE(){
        return NE;
    }
    void Afficher(){
        cout<<"Nom filliere: "<<nomFil<<endl;
        cout<<"Niveau d'etude: "<<NE<<" Annee"<<endl;
    }
    void setNomFil(string &nf){
        nomFil=nf;
    }
    void setNE(NiveauEtude &ne){
        NE=ne.getNE();
    }
};

class Classe{
    string nomC;
    string nf;
    public:
    Classe():nomC(""),nf(""){}
    Classe(string nc,Filiere &f):nomC(nc),nf(f.getNF()){}
    void Afficher(){
        cout<<"Nom classe: "<<nomC<<endl;
        cout<<"Filiere: "<<nf<<endl;
    }
    string getNC(){return nomC;}
    string getnf(){return nf;}
    void setNC(string &nc){
        nomC=nc;
    }
    void setnf(Filiere &f){
        nf=f.getNF();
    }
};

class Etudiant{
    int Matr;
    string nom,prenom,dateNaissance,nclasse;
    public:
    Etudiant(){
        Matr=0;
        nom="";
        prenom="";
        dateNaissance="";
        nclasse="";
    }
    Etudiant(int m,string n,string pr,string dn,string nc):Matr(m),nom(n),prenom(pr),dateNaissance(dn),nclasse(nc){}
    int getMat(){
        return Matr;
    }
    string getNom(){
        return nom;
    }
    string getPrenom(){
        return prenom;
    }
    void setMat(int &m){
        Matr=m;
    }
    void setNom(string &n){
        nom=n;
    }
    void setPrenom(string &pr){
        prenom=pr;
    }
    void setDateNaissance(string &dn){
        dateNaissance=dn;
    }
    void setClasse(string &nouveauC){
        nclasse=nouveauC;
    }
    void Afficher(){
        cout<<"Matricule: "<<Matr<<endl;
        cout<<"Nom: "<<nom<<endl;
        cout<<"Prenom: "<<prenom<<endl;
        cout<<"Date de naissance: "<<dateNaissance<<endl;
        cout<<"Classe: "<<nclasse<<endl;
    }
};

class Departement{
    string nomD;
    public:
    string getND(){
        return nomD;
    }
    Departement(string nD):nomD(nD){}
    ~Departement(){
        cout<<"Departement supprimee "<<endl;
    }
    void Afficher(){
        cout<<"Nom de Departement: "<<nomD<<endl;
    }
    
};
class Personnal{
    protected:
    int num;
    string nom,prenom,nde;
    public:
    Personnal():num(0),nom(""),prenom(""),nde(""){}
    Personnal(int nu,string no,string pr,Departement &d):num(nu),nom(no),prenom(pr),nde(d.getND()){}
    virtual void Afficher(){
        cout<<"Nuemero: "<<num<<endl;
        cout<<"Nom: "<<nom<<endl;
        cout<<"Prenom: "<<prenom<<endl;
        cout<<"Nom de Departement: "<<nde<<endl;
    }
};

class Enseignant:public Personnal{
    public:
    Enseignant():Personnal(){}
    Enseignant(int num,string n,string pre,Departement &de):Personnal(num,n,pre,de){}
    int getNUM(){
        return Personnal::num;
    }
    string getNom(){
        return Personnal::nom;
    }
    string getPrenom(){
        return Personnal::prenom;
    }
    string getDepartment(){
        return Personnal::nde;
    }
    void setNum(int &nu){
        Personnal::num=nu;
    }
    void setNom(string &n){
       Personnal::nom=n;
    }
    void setPrenom(string &pr){
        Personnal::prenom=pr;
    }
    void setDepartement(string &nd){
        Personnal::nde=nd;
    }
    void Afficher(){
        Personnal::Afficher();
    }
};

class Administrateur:public Personnal{
    public:
    Administrateur():Personnal(){}
    Administrateur(int num,string n,string pre,Departement &de):Personnal(num,n,pre,de){}
    void Afficher(){
        Personnal::Afficher();
    }
    int getNUM(){
        return Personnal::num;
    }
    string getNom(){
        return Personnal::nom;
    }
    string getPrenom(){
        return Personnal::prenom;
    }
    
    void setNum(int &nu){
        Personnal::num=nu;
    }
    void setNom(string &n){
       Personnal::nom=n;
    }
    void setPrenom(string &pr){
        Personnal::prenom=pr;
    }
    void setDepartement(string &nd){
        Personnal::nde=nd;
    }
};
 
class Cours{
    string nomCours,nomEns;
    public:
    Cours():nomCours(""),nomEns(""){}
    Cours(string &nCours,Enseignant &e):nomCours(nCours),nomEns(e.getNom()){}
    string getNC(){
        return nomCours;
    }
    string getNomE(){
        return nomEns;
    }
    void setNomCours(string &nc){
        nomCours=nc;
    }
    
    void Afficher(){
        cout<<"Nom de Cours: "<<nomCours<<endl;
    }
    void AffecterEnseignant(Enseignant &e){
        nomEns=e.getNom();
    }
};

class InscriptionCours{
    int Matricule;
    string NomCours,Status="En attente";
    public:
    InscriptionCours(Etudiant &e,Cours &c):Matricule(e.getMat()),NomCours(c.getNC()){}
    void Valider(){
        Status="Valider";
    }
    void Refuser(){
        Status="Refuser";
    }
    int getM(){
        return Matricule;
    }
    string getncour(){
        return NomCours;
    }
    string getStatus(){
        return Status;
    }
    void Afficher(){
        cout<<"Matricule: "<<Matricule<<endl;
        cout<<"Nom du Cour: "<<NomCours<<endl;
    }
};

class Note{
    int m;
    string nc;
    float note;
    public:
    Note():m(0),nc(""),note(0){}
    Note(InscriptionCours &ic,float n):m(ic.getM()),nc(ic.getncour()),note(n){}
    void Afficher(){
        cout<<"Nom de Cours: "<<nc<<"   ";
        cout<<"Note: "<<note<<endl;
    }
    void setNote(float &n){
        note=n;
    }
    void setIC(InscriptionCours &ic){
        m=ic.getM();
        nc=ic.getncour();
    }
    int getM(){
        return m;
    }
    string getncour(){
        return nc;
    }
};

class Absence{
    int m,nbreSeance=0;
    string nc;
    public:
    Absence():m(0),nc(""){}
    Absence(InscriptionCours &ic):m(ic.getM()),nc(ic.getncour()),nbreSeance(1){}
    void setM(int &mat){
        m=mat;
    }
    void setNomCours(string &ncour){
        nc=ncour;
    }
    
    void Afficher(){
        cout<<"Matricule d'Etudiant: "<<m<<endl;
        cout<<"Nom de Cours: "<<nc<<endl;
        cout<<"Nombre de seance: "<<nbreSeance<<endl;
    }
    int getM(){
        return m;
    }
    int getNbrS(){
        return nbreSeance;
    }
    string getncour(){
        return nc;
    }
    
    void NbreSAug(){
        nbreSeance++;
    }
        
    
};


/*--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------*/
//Fonctionnalites Admin 
void GestionEtudiants(vector<Etudiant> &vEt,vector<Classe> vCl,Etudiant &et){
    bool c=true;
    while(c){
        cout<<"1-Ajouter un Etudiant."<<endl;
        cout<<"2-Modifier un Etudiant."<<endl;
        cout<<"3-Supprimer un Etudiant."<<endl;
        cout<<"4-Rechercher un Etudiant."<<endl;
        cout<<"5-Quitter"<<endl;
        cout<<"Saisir votre choix: ";
        int choix;
        cin>>choix;
        if(choix==1){
//Ajouter etudiant
            string n,pr,dn,nomC;int ma;
            cout<<"Saisir un Matricule: "<<endl;
            cin>>ma;
            cout<<"Saisir nom: "<<endl;
            cin>>n;
            cout<<"Saisir le prenom: "<<endl;
            cin>>pr;
            cout<<"Saisir une Date de Naissance: "<<endl;
            cin>>dn;
            cout<<"Saisir une classe: "<<endl;
            cin>>nomC;
//Afficher les classes
            for(int i=0;i<vCl.size();i++){
                cout<<i<<"-"<<vCl[i].getNC()<<endl;
            }
//utiliser les setters pour stocker les infos saisis dans l'objet en parametre si la classe saisi existe
            for(int j=0;j<vCl.size();j++){
                if(nomC==(vCl[j].getNC())){
                    et.setMat(ma);
                    et.setNom(n);
                    et.setPrenom(pr);
                    et.setDateNaissance(dn);
                    et.setClasse(nomC);
                    vEt.push_back(et);
                    cout<<"Etudiant ajouter avec success "<<endl;
                }
                else if((nomC!=(vCl[j].getNC())) && j==(vCl.size())-1){
                    cout<<"Classe non trouve"<<endl;
                }
            }
            
        }
//modifier les infos d'un etudiant saisi
        else if(choix==2){
            string nomEtudientAChanger,prenomEtudientAChanger;
            cout<<"Saisir le nom:"<<endl;
            cin>>nomEtudientAChanger;
            cout<<"Saisir le prenom:"<<endl;
            cin>>prenomEtudientAChanger;
//cette boucle cherche si etudiant saisi existe
            for(int i=0;i<vEt.size();i++){
                if((nomEtudientAChanger==(vEt[i].getNom())) && (prenomEtudientAChanger==(vEt[i].getPrenom()))){
                    cout<<"1-Modifier le nom."<<endl;
                    cout<<"2-Modifier prenom."<<endl;
                    cout<<"3-Modifier la date de Naissance."<<endl;
                    cout<<"4-Modifier la classe."<<endl;
                    int ch;
                    string NCh,PCh,DNCh,NCLCh;
                    cin>>ch;
                    if(ch==1){
                        cout<<"Saisir le nouveau nom: "<<endl;
                        cin>>NCh;
                        vEt[i].setNom(NCh);
                    }
                    else if(ch==2){
                        cout<<"Saisir le nouveau prenom: "<<endl;
                        cin>>PCh;
                        vEt[i].setPrenom(PCh);
                    }
                    else if(ch==3){
                        cout<<"Saisir la nouvelle date de naissance: "<<endl;
                        cin>>DNCh;
                        vEt[i].setDateNaissance(DNCh);
                    }
                    else if(ch==4){
                        cout<<"Saisir le nom de classe: "<<endl;
                        cin>>NCLCh;
                        for(int j=0;j<vCl.size();j++){
                            if(NCLCh==(vCl[j].getNC())){
                                vEt[i].setClasse(NCLCh);
                            }
                            else if((NCLCh!=(vCl[j].getNC())) && j==((vCl.size())-1)){
                                cout<<"Classe non trouve"<<endl;
                            }
                        }
                        
                    }
                }
                else if(((nomEtudientAChanger!=(vEt[i].getNom())) || (prenomEtudientAChanger!=(vEt[i].getPrenom()))) && i==((vEt.size())-1)){
                    cout<<"L'etudiant n'existe pas"<<endl;
                }
            }
            
        }
        else if(choix==3){
            string NomEtudASupprimer,PreNomEtudASupprimer;
            cout<<"Saisir le nom d'Etudiant a supprimer"<<endl;
            cin>>NomEtudASupprimer;
            cout<<"Saisir le prenom d'Etudiant a supprimer"<<endl;
            cin>>PreNomEtudASupprimer;
//cette boucle cherche si etudiant saisi existe si c'est le cas il le supprimer en utilisant erase ; une methode de vector
            for(int i=0;i<vEt.size();i++){
                if((NomEtudASupprimer==(vEt[i].getNom())) && (PreNomEtudASupprimer==(vEt[i].getPrenom()))){
                    vEt.erase(vEt.begin()+i);
                }
                else if(((NomEtudASupprimer!=(vEt[i].getNom())) || (PreNomEtudASupprimer!=(vEt[i].getPrenom()))) && i==((vEt.size())-1)){
                    cout<<"L'etudiant n'existe pas"<<endl;
                }
            }
        }
        else if(choix==4){
            string NomEtARechercher,PreNomEtARechercher;
            cout<<"Saisir le nom d'Etudiant a rechercher"<<endl;
            cin>>NomEtARechercher;
            cout<<"Saisir le prenom d'Etudiant a rechercher"<<endl;
            cin>>PreNomEtARechercher;
            for(int i=0;i<vEt.size();i++){
                if((NomEtARechercher==(vEt[i].getNom())) && (PreNomEtARechercher==(vEt[i].getPrenom()))){
                    vEt[i].Afficher();
                }
                else if(((NomEtARechercher!=(vEt[i].getNom())) || (PreNomEtARechercher!=(vEt[i].getPrenom()))) && i==((vEt.size())-1)){
                    cout<<"L'etudiant n'existe pas"<<endl;
                }
            }
        }
        else if(choix==5){
            return;
        }
    }
}






void GestionPersonnel(vector<Departement> &vD,vector<Enseignant> &vE,vector<Administrateur> &vAdm,Enseignant &en,Administrateur &ad){
    bool c=true;
    while(c){
        cout<<"1-Gestion des enseignants"<<endl;
        cout<<"2-Gestion des Administrateurs"<<endl;
        cout<<"3-retour"<<endl;
        cout<<"Saisir votre choix: "<<endl;
        int ch;
        cin>>ch;
        if(ch==1){
            cout<<"1-Ajouter un enseignant."<<endl;
            cout<<"2-Modifier un enseignant."<<endl;
            cout<<"3-Supprimer un enseignant."<<endl;
            cout<<"4-Rechercher un enseignant."<<endl;
            cout<<"5-Retour"<<endl;
            cout<<"Saisir votre choix: ";
            int choix;
            cin>>choix;
            if(choix==1){
                string n,pr,nomD;int numero;
                cout<<"Saisir Numero: "<<endl;
                cin>>numero;
                cout<<"Saisir nom: "<<endl;
                cin>>n;
                cout<<"Saisir le prenom: "<<endl;
                cin>>pr;
                cout<<"Saisir un Departement: "<<endl;
                for(int i=0;i<vD.size();i++){
                    cout<<i+1<<"-"<<vD[i].getND()<<endl;
                }
                cin>>nomD;
                for(int j=0;j<vD.size();j++){
                    if(nomD==(vD[j].getND())){
                        en.setNum(numero);
                        en.setNom(n);
                        en.setPrenom(pr);
                        en.setDepartement(nomD);
                        vE.push_back(en);
                        cout<<"Enseignant ajouter avec success "<<endl;
                    }
                    else if((nomD!=(vD[j].getND())) && j==(vD.size())-1){
                        cout<<"Departement non trouve"<<endl;
                    }
                }
            }
                
                
            else if(choix==2){
                string nomEnseignantAChanger,prenomEnseignantAChanger;
                cout<<"Saisir le nom:"<<endl;
                cin>>nomEnseignantAChanger;
                cout<<"Saisir le prenom:"<<endl;
                cin>>prenomEnseignantAChanger;
                for(int i=0;i<vE.size();i++){
                    if((nomEnseignantAChanger==(vE[i].getNom())) && (prenomEnseignantAChanger==(vE[i].getPrenom()))){
                        cout<<"1-Modifier le nom."<<endl;
                        cout<<"2-Modifier prenom."<<endl;
                        cout<<"3-Modifier le Departement."<<endl;
                        int ch;
                        string NCh,PCh,NCLCh;
                        cin>>ch;
                        if(ch==1){
                            cout<<"Saisir le nouveau nom: "<<endl;
                            cin>>NCh;
                            vE[i].setNom(NCh);
                        }
                        else if(ch==2){
                            cout<<"Saisir le nouveau prenom: "<<endl;
                            cin>>PCh;
                            vE[i].setPrenom(PCh);
                        }
                    
                        else if(ch==3){
                            cout<<"Saisir le nom de Departement: "<<endl;
                            cin>>NCLCh;
                            for(int j=0;j<vD.size();j++){
                                if(NCLCh==(vD[j].getND())){
                                    vE[i].setDepartement(NCLCh);
                                }
                                else if((NCLCh!=(vD[j].getND())) && j==((vD.size())-1)){
                                    cout<<"Departement non trouve"<<endl;
                                }
                            }
                        
                        }
                    }
                    else if(((nomEnseignantAChanger!=(vE[i].getNom())) || (prenomEnseignantAChanger!=(vE[i].getPrenom()))) && i==((vE.size())-1)){
                        cout<<"L'Enseignant n'existe pas"<<endl;
                    }
                }
            
            }    
                
            else if(choix==3){
                string NomEnsASupprimer,PreNomEnsASupprimer;
                cout<<"Saisir le nom d'Enseignant a supprimer"<<endl;
                cin>>NomEnsASupprimer;
                cout<<"Saisir le prenom d'Enseignant a supprimer"<<endl;
                cin>>PreNomEnsASupprimer;
                for(int i=0;i<vE.size();i++){
                    if((NomEnsASupprimer==(vE[i].getNom())) && (PreNomEnsASupprimer==(vE[i].getPrenom()))){
                        vE.erase(vE.begin()+i);
                    }
                    else if(((NomEnsASupprimer!=(vE[i].getNom())) || (PreNomEnsASupprimer!=(vE[i].getPrenom()))) && i==((vE.size())-1)){
                        cout<<"L'Enseignant n'existe pas"<<endl;
                    }
                }
            }    
            
            else if(choix==4){
            string NomEnsARechercher,PreNomEnsARechercher;
            cout<<"Saisir le nom d'Enseignant a rechercher"<<endl;
            cin>>NomEnsARechercher;
            cout<<"Saisir le prenom d'Enseignant a rechercher"<<endl;
            cin>>PreNomEnsARechercher;
            for(int i=0;i<vE.size();i++){
                if((NomEnsARechercher==(vE[i].getNom())) && (PreNomEnsARechercher==(vE[i].getPrenom()))){
                    vE[i].Afficher();
                }
                else if(((NomEnsARechercher!=(vE[i].getNom())) || (PreNomEnsARechercher!=(vE[i].getPrenom()))) && i==((vE.size())-1)){
                    cout<<"L'Enseignant n'existe pas"<<endl;
                }
            }
        }
        }
        
        else if(ch==2){
            cout<<"1-Ajouter un Administrateur."<<endl;
            cout<<"2-Modifier un Administrateur."<<endl;
            cout<<"3-Supprimer un Administrateur."<<endl;
            cout<<"4-Rechercher un Administrateur."<<endl;
            cout<<"5-Retour"<<endl;
            cout<<"Saisir votre choix: ";
            int choix;
            cin>>choix;
            if(choix==1){
                string n,pr,nomD;int numero;
                cout<<"Saisir Numero: "<<endl;
                cin>>numero;
                cout<<"Saisir nom: "<<endl;
                cin>>n;
                cout<<"Saisir le prenom: "<<endl;
                cin>>pr;
                cout<<"Saisir un Departement: "<<endl;
                cin>>nomD;
                for(int i=0;i<vD.size();i++){
                    cout<<i<<"-"<<vD[i].getND()<<endl;
                }
                for(int j=0;j<vD.size();j++){
                    if(nomD==(vD[j].getND())){
                        ad.setDepartement(nomD);
                        ad.setNum(numero);
                        ad.setPrenom(pr);
                        ad.setNom(n);
                        vAdm.push_back(ad);
                        cout<<"Administrateur ajouter avec success "<<endl;
                    }
                    else if((nomD!=(vD[j].getND())) && j==(vD.size())-1){
                        cout<<"Departement non trouve"<<endl;
                    }
                }
            }
                
                
            else if(choix==2){
                string nomAdminAChanger,prenomAdminAChanger;
                cout<<"Saisir le nom:"<<endl;
                cin>>nomAdminAChanger;
                cout<<"Saisir le prenom:"<<endl;
                cin>>prenomAdminAChanger;
                for(int i=0;i<vAdm.size();i++){
                    if((nomAdminAChanger==(vAdm[i].getNom())) && (prenomAdminAChanger==(vAdm[i].getPrenom()))){
                        cout<<"1-Modifier le nom."<<endl;
                        cout<<"2-Modifier prenom."<<endl;
                        cout<<"3-Modifier le Departement."<<endl;
                        int ch;
                        string NCh,PCh,NCLCh;
                        cin>>ch;
                        if(ch==1){
                            cout<<"Saisir le nouveau nom: "<<endl;
                            cin>>NCh;
                            vAdm[i].setNom(NCh);
                        }
                        else if(ch==2){
                            cout<<"Saisir le nouveau prenom: "<<endl;
                            cin>>PCh;
                            vAdm[i].setPrenom(PCh);
                        }
                    
                        else if(ch==3){
                            cout<<"Saisir le nom de Departement: "<<endl;
                            cin>>NCLCh;
                            for(int j=0;j<vD.size();j++){
                                if(NCLCh==(vD[j].getND())){
                                    vAdm[i].setDepartement(NCLCh);
                                }
                                else if((NCLCh!=(vD[j].getND())) && j==((vD.size())-1)){
                                    cout<<"Departement non trouve"<<endl;
                                }
                            }
                        
                        }
                    }
                    else if(((nomAdminAChanger!=(vAdm[i].getNom())) || (prenomAdminAChanger!=(vAdm[i].getPrenom()))) && i==((vAdm.size())-1)){
                        cout<<"L'Administrateur n'existe pas"<<endl;
                    }
                }
            
            }    
                
            else if(choix==3){
                string NomAdmASupprimer,PreNomAdmASupprimer;
                cout<<"Saisir le nom d'Admin a supprimer"<<endl;
                cin>>NomAdmASupprimer;
                cout<<"Saisir le prenom d'Admin a supprimer"<<endl;
                cin>>PreNomAdmASupprimer;
                for(int i=0;i<vAdm.size();i++){
                    if((NomAdmASupprimer==(vAdm[i].getNom())) && (PreNomAdmASupprimer==(vAdm[i].getPrenom()))){
                        vAdm.erase(vAdm.begin()+i);
                    }
                    else if(((NomAdmASupprimer!=(vAdm[i].getNom())) || (PreNomAdmASupprimer!=(vAdm[i].getPrenom()))) && i==((vAdm.size())-1)){
                        cout<<"L'Administrateur n'existe pas"<<endl;
                    }
                }
            }    
            
            else if(choix==4){
                string NomAdminARechercher,PreNomAdminARechercher;
                cout<<"Saisir le nom d'Enseignant a rechercher"<<endl;
                cin>>NomAdminARechercher;
                cout<<"Saisir le prenom d'Enseignant a rechercher"<<endl;
                cin>>PreNomAdminARechercher;
                for(int i=0;i<vE.size();i++){
                    if((NomAdminARechercher==(vAdm[i].getNom())) && (PreNomAdminARechercher==(vAdm[i].getPrenom()))){
                        vAdm[i].Afficher();
                    }
                    else if(((NomAdminARechercher!=(vAdm[i].getNom())) || (PreNomAdminARechercher!=(vAdm[i].getPrenom()))) && i==((vAdm.size())-1)){
                        cout<<"L'Admin n'existe pas"<<endl;
                    }
                }
            }
            else if(choix==5){return;}
        }
        else if(ch==3){
            return;
        }
    }
}


void gestionCours(vector<Cours> &vC,vector<Enseignant> &vE,vector<Departement> &vD,Cours &cou){
    bool b=true;
    while(b){
        cout<<"1-Ajouter un cours"<<endl;
        cout<<"2-Modifier un cours"<<endl;
        cout<<"3-Supprimer un cours"<<endl;
        cout<<"4-Consulter un cours"<<endl;
        cout<<"5-Retour"<<endl;
        cout<<"Saisir votre choix"<<endl;
        int c;
        cin>>c;
        if(c==1){
            string n,nE;
            cout<<"Saisir nom de cours: "<<endl;
            cin>>n;
            cout<<"Saisir le nom d'un Enseignant"<<endl;
//cette boucle afficher les enseignant pour affecter a un cours
            for(int i=0;i<vE.size();i++){
                vE[i].Afficher();
            }
            cin>>nE;
            for(int i=0;i<vE.size();i++){
                if(nE==(vE[i].getNom())){
                    cou.setNomCours(n);
                    cou.AffecterEnseignant(vE[i]);
                    vC.push_back(cou);
                }
                else if(nE!=(vE[i].getNom()) && i==(vE.size())-1){
                    cout<<"Enseignant non Existant"<<endl;
                }
            }
        }
        
        else if(c==2){
            string n,nE;
            for(int i=0;i<vC.size();i++){
                cout<<i+1<<": ";vC[i].Afficher();
            }
            cout<<"Saisir nom de cours: "<<endl;
            cin>>n;
            for(int i=0;i<vC.size();i++){
                if(n==(vC[i].getNC())){
                    cout<<"1-Modifier le nom"<<endl;
                    cout<<"2-Modifier l'Enseignant responsable"<<endl;
                    int choi;
                    cin>>choi;
                    if(choi==1){
                        cout<<"Saisir le nouveau nom: "<<endl;
                        cin>>n;
                        vC[i].setNomCours(n);
                    }
                    else if(choi==2){
                        cout<<"Saisir le nouveau Enseignant: "<<endl;
                        for(int j=0;j<vE.size();j++){
                            cout<<j+1<<": ";vE[j].Afficher();
                        }
                        cin>>nE;
                        for(int j=0;j<vE.size();j++){
                            if(nE==vE[j].getNom()){
                                vC[i].AffecterEnseignant(vE[j]);
                            }
                            else if(nE!=vE[j].getNom() && j==(vE.size())-1){
                                cout<<"Enseignant non Existant"<<endl;
                            }
                        }
                    }
                }
            }
            
           
        }
        
        else if(c==3){
            cout<<"Saisir le cours a supprimer"<<endl;
            string nc;
            cin>>nc;
            for(int i=0;i<vC.size();i++){
                if(nc==(vC[i].getNC())){
                    vC.erase(vC.begin()+i);
                }
                else if(nc!=(vC[i].getNC()) && i==(vC.size())+1){
                    cout<<"Cours non Existant"<<endl;
                }
            }
        }
        
        else if(c == 4) {
            string DepartementCours;
            cout << "Saisir le Département à Consulter :" << endl;
            for(int i = 0; i < vD.size(); i++) {
                vD[i].Afficher();
            }
            cin >> DepartementCours;
            for(int i = 0; i < vD.size(); i++) {
                if(DepartementCours == vD[i].getND()) {
                    for(int J = 0; J < vE.size(); J++) {
                        if(DepartementCours == vE[J].getDepartment()) {
                            for(int d = 0; d < vC.size(); d++) {
                                if(vE[J].getNom() == vC[d].getNC()) {
                                    vC[d].Afficher();
                                }
                            }
                        }
                    }
                }
            }
        }

        
        else if(c==5){
            return;
        }
        
    }
}


void GestionNotes(vector<InscriptionCours> &vic,vector<Note> &vN,Note &n){
    bool b=true;
    while(b){
        cout<<"1-Ajouter une note"<<endl;
        cout<<"2-Modifier une note"<<endl;
        cout<<"3-Supprimer une note"<<endl;
        cout<<"4-Consulter les notes d'un etudiant"<<endl;
        cout<<"5-Retour"<<endl;
        cout<<"Saisir votre choix: "<<endl;
        int choix;
        cin>>choix;
        int m;float no;string nc;
        if(choix==1){
            cout<<"Saisir un Matricule d'etudiant"<<endl;
            cin>>m;
            for(int i=0;i<vic.size();i++){
                if(m==vic[i].getM()){
                    cout<<"Saisir le nom du cours"<<endl;
                    cin>>nc;
                    if(nc==vic[i].getncour()){
                        cout<<"Saisir une note"<<endl;
                        cin>>no;
                        if(no<=20 && no>=0){
                            n.setNote(no);
                            n.setIC(vic[i]);
                            vN.push_back(n);
                        }
                    }
                    else if(nc!=vic[i].getncour() && i==vic.size()-1){
                        cout<<"Cours non trouver"<<endl;
                    }
                }
                else if(m!=vic[i].getM() && i==vic.size()-1){
                    cout<<"Etudiant non trouver"<<endl;
                }
            }
                
        }
        
        else if(choix==2){
            cout<<"Saisir un Matricule d'etudiant"<<endl;
            cin>>m;
            for(int i=0;i<vic.size();i++){
                if(m==vic[i].getM()){
                    cout<<"Saisir le nom du cours"<<endl;
                    cin>>nc;
                    if(nc==vic[i].getncour()){
                        cout<<"Saisir la nouvelle note"<<endl;
                        cin>>no;
                        if(no<=20 && no>=0){
                            for(int j=0;j<vN.size();j++){
                                if(vic[i].getM()==vN[j].getM() && vic[i].getncour()==vN[j].getncour()){vN[j].setNote(no);}
                            }
                        }
                    }
                    else if(nc!=vic[i].getncour() && i==vic.size()-1){
                        cout<<"Cours non trouver"<<endl;
                    }
                }
                else if(m!=vic[i].getM() && i==vic.size()-1){
                    cout<<"Etudiant non trouver"<<endl;
                }
            }  
        }
        
        else if(choix==3){
            cout<<"Saisir un Matricule d'etudiant"<<endl;
            cin>>m;
            for(int i=0;i<vic.size();i++){
                if(m==vic[i].getM()){
                    cout<<"Saisir le nom du cours"<<endl;
                    cin>>nc;
                    if(nc==vic[i].getncour()){
                        for(int j=0;j<vN.size();j++){
                            if(vic[i].getM()==vN[j].getM() && vic[i].getncour()==vN[j].getncour()){vN.erase(vN.begin()+j);}
                        }
                    }
                    else if(nc!=vic[i].getncour() && i==vic.size()-1){
                        cout<<"Cours non trouver"<<endl;
                    }
                }
                else if(m!=vic[i].getM() && i==vic.size()-1){
                    cout<<"Etudiant non trouver"<<endl;
                }
            }
        }
        
        else if(choix==4){
            cout<<"Saisir un Matricule d'etudiant"<<endl;
            cin>>m;
            for(int i=0;i<vic.size();i++){
                if(m==vic[i].getM()){
                    for(int j=0;j<vN.size();j++){
                        if(vic[i].getM()==vN[j].getM()){vN[j].Afficher();}
                    }
                }
                else if(m!=vic[i].getM() && i==vic.size()-1){
                    cout<<"Etudiant non trouver"<<endl;
                }
            }
        }
        
        else {
            return;
        }
           
    }
}







//cette fonction prend le matricule et le nom de cours en parametre,s'ils existent dans le vector des InscriptionCours ajoute 1 au nbre de seance si non ajoute une nouvelle instance absence au vector
void GestionAbsence(vector<InscriptionCours> &vic,vector<Absence> &vA,Absence &a){
    bool b=true;
    while(b){
        cout<<"1-Ajouter une Absence"<<endl;
        cout<<"2-Supprimer une Absence"<<endl;
        cout<<"3-Consulter les Absences d'un etudiant"<<endl;
        cout<<"4-Retour"<<endl;
        cout<<"Saisir votre choix: "<<endl;
        int choix;
        cin>>choix;
        int m;string nc;
        if(choix==1){
            cout<<"Saisir un matricule"<<endl;
            cin>>m;
            cout<<"Saisir un nom de cours"<<endl;
            cin>>nc;
            for(int i=0;i<vic.size();i++){
                if(m==vic[i].getM() && nc==vic[i].getncour()){
                    for(int d=0;d<vA.size();d++){
                       if(nc==vA[d].getncour() && m==vA[d].getM()){
                            vA[d].NbreSAug();
                        }
                        else if((nc!=vA[d].getncour() || m!=vA[d].getM()) && d==vA.size()-1){
                            a.setNomCours(nc);
                            a.NbreSAug();
                            vA.push_back(a);
                        }
                    }
                    
                }
                    else if(nc!=vic[i].getncour() && m==vic[i].getM() && i==vic.size()-1){
                        cout<<"Cours non Existant"<<endl;
                    }
                    else if(nc==vic[i].getncour() && m!=vic[i].getM() && i==vic.size()-1){
                        cout<<"Cours non Existant"<<endl;
                    }
                
                
            }
               
        }
        
    
        
        else if(choix==2){
            cout<<"Saisir un matricule"<<endl;
            cin>>m;
            cout<<"Saisir un nom de cours"<<endl;
            cin>>nc;
            for(int i=0;i<vic.size();i++){
                if(m==vic[i].getM() && nc==vic[i].getncour()){
                    for(int d=0;d<vA.size();d++){
                       if(nc==vA[d].getncour() && m==vA[d].getM()){
                            vA.erase(vA.begin()+d);
                        }
                        else if((nc!=vA[d].getncour() || m!=vA[d].getM()) && d==vA.size()-1){
                            cout<<"L'Etudiant n'a aucune Absence"<<endl;
                        }
                    }
                    
                }
                    else if(nc!=vic[i].getncour() && m==vic[i].getM() && i==vic.size()-1){
                        cout<<"Cours non Existant"<<endl;
                    }
                    else if(nc==vic[i].getncour() && m!=vic[i].getM() && i==vic.size()-1){
                        cout<<"Cours non Existant"<<endl;
                    }
                
                
            }
        }
        
        else if(choix==3){
            cout<<"Saisir un Matricule d'etudiant"<<endl;
            cin>>m;
            for(int i=0;i<vic.size();i++){
                if(m==vic[i].getM()){
                    for(int j=0;j<vA.size();j++){
                        if(vic[i].getM()==vA[j].getM()){vA[j].Afficher();}
                    }
                }
                else if(m!=vic[i].getM() && i==vic.size()-1){
                    cout<<"Etudiant non trouver"<<endl;
                }
            }
        }
                  
         
        
        
        else {
            return;
        }
           
    }
}

void Gestiondesfillieres(vector<NiveauEtude> &vNE,vector<Filiere> &vfl,Filiere &fil){
    bool b=true;
    while(b){
        cout<<"1-Ajouter une filliere"<<endl;
        cout<<"2-Modifier une filliere"<<endl;
        cout<<"3-Supprimer une filliere"<<endl;
        cout<<"4-Consulte la liste des fillieres"<<endl;
        cout<<"5-Retour"<<endl;
        cout<<"Saisir votre choix: "<<endl;
        int choix;
        cin>>choix;
        if(choix==1){
            cout<<"Saisir un nom de filliere"<<endl;
            string nomf;
            cin>>nomf;
            for(int i=0;i<vfl.size();i++){
                if(nomf!=vfl[i].getNF() && i==vfl.size()-1){
                    fil.setNomFil(nomf);
                    cout<<"Saisir un niveau d'etude"<<endl;
                    int ne;
                    cin>>ne;
                    for(int j=0;j<vNE.size();j++){
                        if(ne==vNE[j].getNE()){
                            fil.setNE(vNE[j]);
                            vfl.push_back(fil);
                            return;
                        }
                        else if(ne!=vNE[j].getNE() && j==vNE.size()-1){
                            cout<<"NiveauEtude nom connu"<<endl;
                        }
                    }
                }
            }
        }
        else if(choix==2){
            cout<<"Saisir un nom de Filiere"<<endl;
            string nf;
            cin>>nf;
            for(int i=0;i<vfl.size();i++){
                if(nf==vfl[i].getNF()){
                    cout<<"Saisir le nouveau nom"<<endl;
                    string NouvNF;
                    cin>>NouvNF;
                    vfl[i].setNomFil(NouvNF);
                }
                else if(nf==vfl[i].getNF() && i==vfl.size()-1){
                    cout<<"Filiere non trouver"<<endl;
                }
            }
            
          
        }
        else if(choix==3){
            cout<<"Saisir un nom de Filiere"<<endl;
            string nf;
            cin>>nf;
            for(int i=0;i<vfl.size();i++){
                if(nf==vfl[i].getNF()){
                    vfl.erase(vfl.begin()+i);
                }
                else if(nf==vfl[i].getNF() && i==vfl.size()-1){
                    cout<<"Filiere non trouver"<<endl;
                }
            }
        }
        
        else if(choix==4){
            for(int i=0;i<vfl.size();i++){
                vfl[i].Afficher();
            }
        }
        else if(choix==5){
            return;
        }
        else{
            cout<<"Choix Inconnu"<<endl;
        }
    }
}



void GestiondesClasse(vector<Filiere> &vf,vector<Classe> &vcla,Classe &cla){
    bool b=true;
    while(b){
            cout<<"1-Ajouter une Classe"<<endl;
        cout<<"2-Modifier une Classe"<<endl;
        cout<<"3-Supprimer une Classe"<<endl;
        cout<<"4-Consulte la liste des Classe"<<endl;
        cout<<"5-Retour"<<endl;
        cout<<"Saisir votre choix: "<<endl;
        int choix;
        cin>>choix;
        if(choix==1){
            cout<<"Saisir un nom de Classe"<<endl;
            string nomc;
            cin>>nomc;
            for(int i=0;i<vcla.size();i++){
                if(nomc!=vcla[i].getNC() && i==vcla.size()-1){
                    cla.setNC(nomc);
                    cout<<"Saisir une  Filiere"<<endl;
                    string nf;
                    cin>>nf;
                    for(int j=0;j<vf.size();j++){
                        if(nf==vf[j].getNF()){
                            cla.setnf(vf[j]);
                            vcla.push_back(cla);
                            return;
                        }
                        else if(nf!=vf[j].getNF() && j==vf.size()-1){
                            cout<<"Filiere nom connu"<<endl;
                        }
                    }
                }
            }
        }
        else if(choix==2){
            cout<<"Saisir un nom de classe"<<endl;
            string nc;
            cin>>nc;
            for(int i=0;i<vcla.size();i++){
                if(nc==vcla[i].getNC()){
                    cout<<"Saisir le nouveau nom"<<endl;
                    string NouvNC;
                    cin>>NouvNC;
                    vcla[i].setNC(NouvNC);
                }
                else if(nc!=vcla[i].getNC() && i==vcla.size()-1){
                    cout<<"Classe non trouver"<<endl;
                }
            }
            
          
        }
        else if(choix==3){
            cout<<"Saisir un nom de Classe"<<endl;
            string nc;
            cin>>nc;
            for(int i=0;i<vcla.size();i++){
                if(nc==vcla[i].getNC()){
                    vcla.erase(vcla.begin()+i);
                }
                else if(nc==vcla[i].getNC() && i==vcla.size()-1){
                    cout<<"Classe non trouver"<<endl;
                }
            }
        }
        
        else if(choix==4){
            for(int i=0;i<vcla.size();i++){
                vcla[i].Afficher();
            }
        }
        else if(choix==5){
            return;
        }
        else{
            cout<<"Choix Inconnu"<<endl;
        }
    }
}



/*--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------*/
//Fonctionnalites d'etudiant
void AfficherInfos(int &nu,vector<Etudiant> &vEt){
    for(int i=0;i<vEt.size();i++){
        if(nu==vEt[i].getMat()){
            vEt[i].Afficher();
        }
    }
}
//Les cours afficher sont les cours valider par le responsble de cours
void AfficherMesCours(int &nu, vector<InscriptionCours> &vInsC) {
    bool enrolled = false; 
    for(int i = 0; i < vInsC.size(); i++) {
        if(nu == vInsC[i].getM() && vInsC[i].getStatus() == "Valider") {
            cout << "Cours " << i + 1 << ") ";
            cout << vInsC[i].getncour() << endl;
            enrolled = true; 
        }
    }
    if(!enrolled) {
        cout << "Vous n'etes pas inscrit aux cours." << endl;
    }
}

//cette function permet l'etudiant de consulter la liste des cours disponnible et s'inscrire a ses choix 
void InscriptionauxCours(int &nu,vector<Etudiant> &vEt,vector<Cours> &vC,vector<InscriptionCours> &viC){
    for(int i=0;i<vC.size();i++){
        cout<<vC[i].getNC()<<endl;
    }
    cout<<"S'inscrire au cour: "<<endl;
    string NomC;
    cin>>NomC;
    for(int i=0;i<vC.size();i++){
        if(NomC==vC[i].getNC()){
            for(int j=0;j<vEt.size();j++){
                if(nu==vEt[j].getMat()){
                    for(int k=0;k<viC.size();k++){
                        if(NomC!=viC[k].getncour()){
                            InscriptionCours IC(vEt[j],vC[i]);
                            viC.push_back(IC);
                        }
                        else{
                            cout<<"Vous etes deja inscrit a ce cours: "<<endl;
                        }
                        
                    }
                }
            }
        }
    }
}


void AfficherMesNotes(int &num,vector<Note> &vn){
    for(int i=0;i<vn.size();i++){
        if(num==vn[i].getM()){
            vn[i].Afficher();
        }
    }
}
void AfficherMesAbs(int &num,vector<Absence> &va){
    for(int i=0;i<va.size();i++){
        if(num==va[i].getM()){
            cout<<"Nom du cours: "<<va[i].getncour()<<"  "<<endl;
            cout<<"Nombre de seance: "<<va[i].getNbrS()<<endl;
            
        }
    }
}


/*--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------*/

void AfficherInfosEns(int &nu,vector<Enseignant> &vEn){
    for(int i=0;i<vEn.size();i++){
        if(nu==vEn[i].getNUM()){
            vEn[i].Afficher();
        }
    }
}
//afficher les cours affecter a l'enseignant connecter
void AfficherMesCoursEns(int &nu, vector<Enseignant> &vEn, vector<Cours> &vc) {
    for(int i = 0; i < vEn.size(); i++) {
        if(nu == vEn[i].getNUM()) {
            for(int j = 0; j < vc.size(); j++) {
                if(vEn[i].getNom() == vc[j].getNomE()) {
                    cout << "Cours: " << j + 1 << endl;
                    cout << vc[j].getNC() << endl;
                }
                else if(vEn[i].getNom() != vc[j].getNomE() && j==vc.size()-1){
                    cout << "Aucun cours n'a ete affecter " <<endl;
                }
                
            }
            
        }
    }
    
}
//Possibilite de validation ou refus d'une inscription
void AfficherEnsInscriptions(int &nu, vector<Enseignant> &vEn, vector<Cours> &vc,vector<InscriptionCours> &vic,vector<Etudiant> &ve){
    for(int i=0;i<vEn.size();i++){
        if(nu==vEn[i].getNUM()){
            for(int j=0;j<vc.size();j++){
                if(vEn[i].getNom()==vc[j].getNomE()){
                    for(int k=0;k<vic.size();k++){
                        if(vc[j].getNC()==vic[k].getncour() && vic[k].getStatus()=="En attente"){
                            cout<<"Matricule: "<<vic[k].getM()<<"   ";
                            for(int d=0;d<ve.size();d++){
                                if(vic[k].getM()==ve[d].getMat()){
                                    cout<<"Nom: "<<ve[d].getNom()<<"   ";
                                    cout<<"Prenom: "<<ve[d].getPrenom()<<endl;
                                    cout<<"1-Valider un etudiant"<<endl;
                                    cout<<"2-Refuser un etudiant"<<endl;
                                    int choix,n;
                                    cin>>choix;
                                    if(choix==1){
                                        cout<<"Saisir le Matricule d'etudiant"<<endl;
                                        cin>>n;
                                        for(int l=0;l<vic.size();l++){
                                            if(n==vic[l].getM()){
                                                vic[l].Valider();
                                            }
                                            else if(n!=vic[l].getM() && l==vic.size()-1){
                                                cout<<"Matricule non trouver"<<endl;
                                            }
                                        }
                                    }
                                    else if(choix==2){
                                         cout<<"Saisir le Matricule d'etudiant"<<endl;
                                        cin>>n;
                                        for(int l=0;l<vic.size();l++){
                                            if(n==vic[l].getM()){
                                                vic[l].Refuser();
                                            }
                                            else if(n!=vic[l].getM() && l==vic.size()-1){
                                                cout<<"Matricule non trouver"<<endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}




/*--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------*/

int main(){
    NiveauEtude nve(1);
    vector<NiveauEtude> vNEt;
    vNEt.push_back(nve);
    vNEt.push_back(nve);
    vNEt.push_back(nve);
    
    Filiere f1("INformatique",nve);
    Filiere f2("Reseaux",nve);
    Filiere f3("Genie civil",nve);
    vector<Filiere> vFil;
    vFil.push_back(f1);
    vFil.push_back(f2);
    vFil.push_back(f3);
    
    Classe c1("Inf1",f1);
    vector<Classe> vCl;
    vCl.push_back(c1);
    
    Etudiant e1(1,"fsdf","Ahmed","2/3/2000",c1.getNC());
    vector<Etudiant> vEtud;
    vEtud.push_back(e1);
    
    Departement d1("Info"),d2("Activities");
    vector<Departement> vDep;
    vDep.push_back(d1);
    vDep.push_back(d2);
    
    Enseignant es1(1,"fdsf","hiba",d1),es2(2,"grfg","Abdellah",d2);
    vector<Enseignant> vEns;
    vEns.push_back(es1);
    vEns.push_back(es2);
    
    Administrateur ad1(2,"fgt","Youness",d2);
    vector<Administrateur> vAdmin;
    vAdmin.push_back(ad1);
    
    string nc="fdsgdg";
    Cours co(nc,es1);
    vector<Cours> vCours;
    vCours.push_back(co);
    
    InscriptionCours IC(e1,co);
    vector<InscriptionCours> vIC;
    vIC.push_back(IC);
    
    Note n1(IC,15);
    vector<Note> vNote;
    vNote.push_back(n1);
    
    Absence ab1(IC);
    vector<Absence> vAbs;
    vAbs.push_back(ab1);
    
    
    while(true){
        cout<<"Saisir votre Numero:"<<endl;
        int num;
        cin>>num;
        cout<<"Saisir votre role:"<<endl;
        string role;
        cin>>role;
        Etudiant etu;Enseignant ens;Administrateur adm;Cours cours1;Note note1;Absence absence1;Classe clas6;Filiere fill;
        if(role=="Etudiant"){
            for(int i=0;i<vEtud.size();i++){
                if(num==vEtud[i].getMat()){
                    bool t=true;
                    cout<<"Bienvenue "<<vEtud[i].getPrenom()<<" "<<vEtud[i].getNom()<<endl;
                    while(t){
                        cout<<"1-Afficher mes Information."<<endl;
                        cout<<"2-Afficher mes cours."<<endl;
                        cout<<"3-S'inscrire a des cours."<<endl;
                        cout<<"4-Afficher mes notes."<<endl;
                        cout<<"5-Afficher mes Absences."<<endl;
                        cout<<"6-Quiter"<<endl;
                        int c;
                        cin>>c;
                        if(c==1){
                            AfficherInfos(num,vEtud);
                        }
                        else if(c==2){
                            AfficherMesCours(num,vIC);
                        }
                        else if(c==3){
                            InscriptionauxCours(num,vEtud,vCours,vIC);
                        }
                        else if(c==4){
                            AfficherMesNotes(num,vNote);
                        }
                        else if(c==5){
                            AfficherMesAbs(num,vAbs);
                        }
                        else if(c==6){
                             t=false;
                        }
                        else{
                            cout<<"Choix Inconnu"<<endl;
                        }
                   
                    }    
                    }
                else if(num!=vEtud[i].getMat() && i==(vEtud.size())-1){
                    cout<<"Matricule non connu."<<endl;
                }
                
            }
        }
        else if(role=="Admin"){
            for(int i=0;i<vAdmin.size();i++){
                if(num==vAdmin[i].getNUM()){
                    bool t=true;
                    cout<<"Bienvenue "<<vAdmin[i].getPrenom()<<" "<<vAdmin[i].getNom()<<endl; 
                    while(t){
                        cout<<"1-Gestion des Etudiants."<<endl;
                        cout<<"2-Gestion des Personnels."<<endl;
                        cout<<"3-Gestion des Cours."<<endl;
                        cout<<"4-Gestion des Notes."<<endl;    
                        cout<<"5-Gestion des Absences."<<endl;
                        cout<<"6-Gestion des fillieres."<<endl;
                        cout<<"7-Gestion des classes."<<endl;
                        cout<<"8-Quitter."<<endl;
                        cout<<"Saisir votre choix: ";
                        int choix;
                        cin>>choix;
                        if(choix==1){
                            
                            GestionEtudiants(vEtud,vCl,etu);
                        }
                        else if(choix==2){
                            
                            GestionPersonnel(vDep,vEns,vAdmin,ens,adm);
                        }
                        else if(choix==3){
                            
                            gestionCours(vCours,vEns,vDep,cours1);
                        }
                        else if(choix==4){
                           
                            GestionNotes(vIC,vNote,note1);
                        }
                        else if(choix==5){
                            GestionAbsence(vIC,vAbs,absence1);
                        }
                        else if(choix==6){
                            Gestiondesfillieres(vNEt,vFil,fill);
                        }
                        else if(choix==7){
                            GestiondesClasse(vFil,vCl,clas6);
                        }
                        else if(choix==8){
                             t=false;
                        }
                        else{
                            cout<<"Choix Inconnu"<<endl;
                        }
                    }
                }
                else if(num!=vAdmin[i].getNUM() && i==(vAdmin.size())-1){
                    cout<<"Admin non connu."<<endl;
                }
            }
        }
         else if(role=="Enseignant"){
            for(int i=0;i<vEns.size();i++){
                if(num==vEns[i].getNUM()){
                    bool d=true;
                    cout<<"Bienvenue "<<vEns[i].getPrenom()<<" "<<vEns[i].getNom()<<endl;
                    while(d){
                        cout<<"1-Afficher mes Information."<<endl;
                        cout<<"2-Afficher mes cours."<<endl;
                        cout<<"3-Afficher les inscriptions"<<endl;
                        cout<<"4-Afficher mon Emploi du temps."<<endl;
                        cout<<"5-Quiter"<<endl;
                        int c;
                        cin>>c;
                        if(c==1){
                            AfficherInfosEns(num,vEns);
                        }
                        else if(c==2){
                            AfficherMesCoursEns(num,vEns,vCours);
                        }
                        else if(c==3){
                            AfficherEnsInscriptions(num,vEns,vCours,vIC,vEtud);
                        }
                        else if(c==4){
                            
                        }
                        else if(c==5){
                             d=false;
                        }
                        else{
                            cout<<"Choix Inconnu"<<endl;
                        }
                    }
                }
                else if(num!=vEns[i].getNUM() && i==vEns.size()-1){
                    cout<<"Enseignant non existant"<<endl;
                }
            }
        }
    
    }
    
    return 0;
}


