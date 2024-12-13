    #include <iostream>
    #include<iomanip>
    #include <string>
    #include <vector>
    #include <queue>
    #include <deque>
    #include <stack>
    #include <sstream>
    using namespace std;

    const int wysokosc = 26;
    const int szerokosc = 57;
    
    class game{
        private:
        class karta{
            public:
            string symbol;
            string kolor;
            bool czyOdkryta;
            int ranga;
            int czyCzarny;
        
            karta(string s, string k, bool odkryta, int ranga, int czarny) : symbol(s), kolor(k), czyOdkryta(odkryta), ranga(ranga), czyCzarny(czarny) {}
        };

    const karta pusta ={"0", "", true, 0, 0};
        vector<vector<karta>> k_vec;
        queue<karta> kolejka;
        deque<karta> przewijanie;
        stack<karta> s1;
        stack<karta> s2;
        stack<karta> s3;
        stack<karta> s4;
        
        public:
    int przewijaniex = 0;
    int przewijaniey = 1;
    int przewijaniez = 2;

    int kartaRanga(karta karta){
        return karta.ranga;
    }

    string kartaKolor(karta karta){
        return karta.kolor;
    }

    string kartaString(karta karta){
        return karta.symbol+karta.kolor;
    }

    karta kartObjekt(const string kart){
    string symbol;
    string kolor;
    bool czyOdkryta = true;
    int ranga = 0;
    int czyCzarny = 0;
     if (kart.size() == 3) {
        symbol = kart.substr(0, 2);
        kolor = kart.substr(2, 1);
    } else {
        symbol = kart.substr(0, 1);
        kolor = kart.substr(1, 1);
    }

    if (symbol == "2") ranga = 2;
    else if (symbol == "3") ranga = 3;
    else if (symbol == "4") ranga = 4;
    else if (symbol == "5") ranga = 5;
    else if (symbol == "6") ranga = 6;
    else if (symbol == "7") ranga = 7;
    else if (symbol == "8") ranga = 8;
    else if (symbol == "9") ranga = 9;
    else if (symbol == "10") ranga = 10;
    else if (symbol == "J") ranga = 11;
    else if (symbol == "Q") ranga = 12;
    else if (symbol == "K") ranga = 13;
    else if (symbol == "A") ranga = 1;

    if (kolor == "c" || kolor == "s") czyCzarny = 1;

    karta nowa(symbol, kolor, czyOdkryta, czyCzarny, ranga);
    return nowa;
    }

    void nielegalny(){
        cout << "nieprawidlowy ruch, nacisnij jakikolwiek przycisk" << endl;
            system("pause");
            return;
    }

    bool check_win(){
        stack<karta> ref1 = s1;
        stack<karta> ref2 = s2;
        stack<karta> ref3 = s3;
        stack<karta> ref4 = s4;
        int licznik = 0;
        for(int i =0; i<k_vec[0].size(); i++){
        if (k_vec[0][i].czyOdkryta == true) licznik++;}
        for(int i=0; i<k_vec[1].size(); i++){
            if (k_vec[1][i].czyOdkryta == true ) licznik++;
        }
         for(int i=0; i<k_vec[2].size(); i++){
            if (k_vec[2][i].czyOdkryta == true ) licznik++;
        }
         for(int i=0; i<k_vec[3].size(); i++){
            if (k_vec[3][i].czyOdkryta == true ) licznik++;
        }
         for(int i=0; i<k_vec[4].size(); i++){
            if (k_vec[4][i].czyOdkryta == true ) licznik++;
        }
         for(int i=0; i<k_vec[5].size(); i++){
            if (k_vec[5][i].czyOdkryta == true ) licznik++;
        }
         for(int i=0; i<k_vec[6].size(); i++){
            if (k_vec[6][i].czyOdkryta == true ) licznik++;
        }
        while(!ref1.empty()){
            if(ref1.top().czyOdkryta == true) licznik++;
            ref1.pop();
        }
        while(!ref2.empty()){
            if(ref2.top().czyOdkryta == true) licznik++;
            ref2.pop();
        }
        while(!ref3.empty()){
            if(ref3.top().czyOdkryta == true) licznik++;
            ref3.pop();
        }
        while(!ref4.empty()){
            if(ref4.top().czyOdkryta == true) licznik++;
            ref4.pop();
        }
        for(int i=0; i<przewijanie.size(); i++) {
            if (przewijanie[i].czyOdkryta == true) licznik++;
        }
        return (przewijanie.empty() && licznik==56);
        }
    
void przewijaj(int &przewijaniex, int &przewijaniey, int &przewijaniez, deque<karta> &przewijanie){
if(przewijanie.size()>3){
    if((przewijaniex + 1) >= przewijanie.size()){
                        przewijaniex = 0;
                        przewijaniey = 1;
                        przewijaniez = 2;
                    }
                    else if(( przewijaniey+1) >= przewijanie.size()){
                        przewijaniey = 0;
                        przewijaniez=1; 
                    }
                    else if((przewijaniez+1) >= przewijanie.size()) {
                        przewijaniez=0;}
                    else{
                        przewijaniex +=1;
                        przewijanie[przewijaniex].czyOdkryta=true;
                    przewijaniey +=1;
                    przewijanie[przewijaniey].czyOdkryta=true;
                    przewijaniez +=1;
                    przewijanie[przewijaniez].czyOdkryta=true;
                    }
}
    else if(przewijanie.size() == 3){
        przewijaniey= przewijaniex;
        przewijaniex = przewijaniez;
        przewijaniez = przewijaniey;
    }
    else if(przewijanie.size() == 2){
        przewijaniex= przewijaniey;
        przewijaniey= przewijaniex;
    }
}

    void ruch(){
        string ruch;
        cout << "podaj ruch: "; 
        getline(cin, ruch);
        istringstream  stream(ruch);
        int start;
        string kart;
        int koniec;
        stream >> start;
        stream >> kart;
        stream >> koniec;
        int y = start-1;
        int x = koniec -1;
        if(start == 0 && kart.size()==0) przewijaj(przewijaniex, przewijaniey, przewijaniez, przewijanie);
        else if(start == 0 && kart.size()!=0 ){
            if( 1 <= koniec && koniec <= 7){
                if(start != koniec && przewijanie.at(przewijaniex).ranga == (k_vec[koniec-1].back().ranga-1) && przewijanie.at(przewijaniex).czyCzarny != k_vec[koniec-1].back().czyCzarny){
                if(kartaString(przewijanie[przewijaniex]) == kart){
                    k_vec[koniec-1].push_back(przewijanie[przewijaniex]); 
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
                }
                k_vec[koniec-1].at(k_vec[koniec-1].size()-1).czyOdkryta = true;
            }
            else if(start != koniec && przewijanie.at(przewijaniex).ranga == 13 && k_vec[koniec-1].empty()){
                if(kartaString(przewijanie[przewijaniex]) == kart){
                    k_vec[koniec-1].push_back(przewijanie[przewijaniex]); 
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
                }
                k_vec[koniec-1].at(k_vec[koniec-1].size()-1).czyOdkryta = true;
            }
            else nielegalny();
            }
            else if(koniec == 8){
                if(s1.size()>1 && start != koniec && przewijanie.at(przewijaniex).ranga == (s1.top().ranga+1) && s1.top().kolor == przewijanie.at(przewijaniex).kolor) {
                karta temp = przewijanie.at(przewijaniex);
                    s1.push(temp);
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
            }
            else if(s1.size() == 1 && start != koniec && przewijanie.at(przewijaniex).ranga == 1){
                karta temp = przewijanie.at(przewijaniex);
                    s1.push(temp);
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
            }
            else nielegalny();
            }
            else if(koniec == 9){
                 if(s2.size()>1 && start != koniec && przewijanie.at(przewijaniex).ranga == (s2.top().ranga+1) && s2.top().kolor == przewijanie.at(przewijaniex).kolor) {
                karta temp = przewijanie.at(przewijaniex);
                    s2.push(temp);
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
            }
            else if(s2.size() == 1 && start != koniec && przewijanie.at(przewijaniex).ranga == 1){
                karta temp = przewijanie.at(przewijaniex);
                    s2.push(temp);
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
            }
            else nielegalny();
            }
            else if(koniec == 10){
                if(s3.size()>1 && start != koniec && przewijanie.at(przewijaniex).ranga == (s3.top().ranga+1) && s3.top().kolor == przewijanie.at(przewijaniex).kolor) {
                karta temp = przewijanie.at(przewijaniex);
                    s3.push(temp);
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
            }
            else if(s3.size() == 1 && start != koniec && przewijanie.at(przewijaniex).ranga == 1){
                karta temp = przewijanie.at(przewijaniex);
                    s3.push(temp);
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
            }
            else nielegalny();
            }
            else if(koniec == 11){
                if(s4.size()>1 && start != koniec && przewijanie.at(przewijaniex).ranga == (s4.top().ranga+1) && s4.top().kolor == przewijanie.at(przewijaniex).kolor) {
                karta temp = przewijanie.at(przewijaniex);
                    s4.push(temp);
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
            }
            else if(s4.size() == 1 && start != koniec && przewijanie.at(przewijaniex).ranga == 1){
                karta temp = przewijanie.at(przewijaniex);
                    s4.push(temp);
                    przewijanie.erase(przewijanie.begin()+przewijaniex);
            }
            else nielegalny();
            }
           else {
            nielegalny();
            }   
        }
        else if(7 >= start && start >= 1 && kart.size()!=0)
        {
         if (k_vec[y].size() == 1) {
          if(koniec == 8){
             if(s1.size()>1 && start != koniec && k_vec[start-1].back().ranga == (s1.top().ranga+1) && s1.top().kolor == k_vec[start-1].back().kolor) {
                s1.push(k_vec[y].back());
                k_vec[y].pop_back();
            }
            else if(s1.size() == 1 && start != koniec && k_vec[start-1].back().ranga == 1){
                s1.push(k_vec[y].back());
                k_vec[y].pop_back();
            }
            else nielegalny();
          }
         else if(koniec == 9) {
             if(s2.size()>1 && start != koniec && k_vec[start-1].back().ranga == (s2.top().ranga+1) && s2.top().kolor == k_vec[start-1].back().kolor) {
                s2.push(k_vec[y].back());
                k_vec[y].pop_back();
            }
            else if(s2.size() == 1 && start != koniec && k_vec[start-1].back().ranga == 1){
                s2.push(k_vec[y].back());
                k_vec[y].pop_back();
            }
            else nielegalny();
          }
         else if(koniec == 10) {
             if(s3.size()>1 && start != koniec && k_vec[start-1].back().ranga == (s3.top().ranga+1) && s3.top().kolor == k_vec[start-1].back().kolor) {
                s3.push(k_vec[y].back());
                k_vec[y].pop_back();
            }
            else if(s3.size() == 1 && start != koniec && k_vec[start-1].back().ranga == 1){
                s3.push(k_vec[y].back());
                k_vec[y].pop_back();
            }
            else nielegalny();
          }
         else if(koniec == 11) {
             if(s4.size()>1 && start != koniec && k_vec[start-1].back().ranga == (s4.top().ranga+1) && s4.top().kolor == k_vec[start-1].back().kolor) {
                s4.push(k_vec[y].back());
                k_vec[y].pop_back();
            }
            else if(s4.size() == 1 && start != koniec && k_vec[start-1].back().ranga == 1){
                s4.push(k_vec[y].back());
                k_vec[y].pop_back();
            }
            else nielegalny();
          }
          else if(koniec >= 1 && koniec <= 7 && start != koniec && k_vec[start-1].back().ranga == (k_vec[koniec-1].back().ranga-1) && k_vec[start-1].back().czyCzarny != k_vec[koniec-1].back().czyCzarny) {
            k_vec[x].push_back(k_vec[y].back());
          k_vec[y].pop_back();}
          else if(koniec >= 1 && koniec <= 7 && start != koniec && k_vec[start-1].back().ranga == 13 && k_vec[koniec-1].empty()){
            k_vec[x].push_back(k_vec[y].back());
          k_vec[y].pop_back();}
          else nielegalny();
          }
    
    else{ 
          if(koniec >= 1 && koniec <= 7 && start != koniec && k_vec[start-1].back().ranga == (k_vec[koniec-1].back().ranga-1) && k_vec[start-1].back().czyCzarny != k_vec[koniec-1].back().czyCzarny){
            k_vec[x].push_back(k_vec[y].back()); 
            k_vec[y].pop_back();
          } 
          else if(koniec >= 1 && koniec <= 7 && start != koniec && k_vec[start-1].back().ranga == 13 && k_vec[koniec-1].empty()) k_vec[x].push_back(k_vec[y].back()); 
          else if(koniec == 8){
            if(s1.size()>1 && start != koniec && k_vec[start-1].back().ranga == (s1.top().ranga+1) && s1.top().kolor == k_vec[start-1].back().kolor) {
                s1.push(k_vec[y].back());
                k_vec[y].pop_back();
          k_vec[y].at(k_vec[y].size()-1).czyOdkryta = true;
            }
            else if(s1.size() == 1 && start != koniec && k_vec[start-1].back().ranga == 1){
                s1.push(k_vec[y].back());
                k_vec[y].pop_back();
          k_vec[y].at(k_vec[y].size()-1).czyOdkryta = true;
            }
            else nielegalny();
            }
            else if(koniec ==9){
                 if(s2.size()>1 && start != koniec && k_vec[start-1].back().ranga == (s2.top().ranga+1) && s2.top().kolor == k_vec[start-1].back().kolor) {
                s2.push(k_vec[y].back());
                k_vec[y].pop_back();
          k_vec[y].at(k_vec[y].size()-1).czyOdkryta = true;
            }
            else if(s2.size() == 1 && start != koniec && k_vec[start-1].back().ranga == 1){
                s2.push(k_vec[y].back());
                k_vec[y].pop_back();
          k_vec[y].at(k_vec[y].size()-1).czyOdkryta = true;
            }
            else nielegalny();
            }
            else if(koniec == 10){
                 if(s3.size()>1 && start != koniec && k_vec[start-1].back().ranga == (s3.top().ranga+1) && s3.top().kolor == k_vec[start-1].back().kolor) {
                s3.push(k_vec[y].back());
                k_vec[y].pop_back();
          k_vec[y].at(k_vec[y].size()-1).czyOdkryta = true;
            }
            else if(s3.size() == 1 && start != koniec && k_vec[start-1].back().ranga == 1){
                s3.push(k_vec[y].back());
                k_vec[y].pop_back();
          k_vec[y].at(k_vec[y].size()-1).czyOdkryta = true;
            }
            else nielegalny();
            }
            else if(koniec ==11){
                 if(s4.size()>1 && start != koniec && k_vec[start-1].back().ranga == (s4.top().ranga+1) && s4.top().kolor == k_vec[start-1].back().kolor) {
                s4.push(k_vec[y].back());
                k_vec[y].pop_back();
          k_vec[y].at(k_vec[y].size()-1).czyOdkryta = true;
            }
            else if(s4.size() == 1 && start != koniec && k_vec[start-1].back().ranga == 1){
                s4.push(k_vec[y].back());
                k_vec[y].pop_back();
            k_vec[y].at(k_vec[y].size()-1).czyOdkryta = true;
            }
            else nielegalny();
        }         
        else nielegalny();
    }
        }
     if (8 <= start && start <= 11) { 
        stack<karta>* startStos;
        if (start == 8) startStos = &s1;
        else if (start == 9) startStos = &s2;
        else if (start == 10) startStos = &s3;
        else if (start == 11) startStos = &s4;

        if (startStos->size()>1) {
            karta topCard = startStos->top();
                if (koniec != start && startStos ->size()>1 && k_vec[koniec-1].size()!= 0 && k_vec[koniec-1].back().ranga == startStos->top().ranga+1 && k_vec[koniec-1].back().czyCzarny!= startStos->top().czyCzarny) {
                    k_vec[koniec-1].push_back(topCard);
                    startStos->pop();
                }
                else if(koniec != start && startStos ->size()>1 && k_vec[koniec-1].size() == 0 && startStos->top().ranga == 13){
                    k_vec[koniec-1].push_back(topCard);
                    startStos->pop();
                }
                else {
                    nielegalny();
                }
        }
        else {
            nielegalny();
        }
    }
        }
        void pasjans(){       
    tworz_kolejke(talia);
    tworz_vectory();
    tworz_przewijanie(kolejka, przewijanie);
    do{
        system("cls");
        piszMape();
        ruch();
        check_win();
    } while(!check_win());
    system("cls");
    cout <<"\nNiezla wygrana ;00" << endl;
    system("pause"); 
    }

        game() {
        s1.push(pusta);
        s2.push(pusta);
        s3.push(pusta);
        s4.push(pusta);
    }

        vector<karta> talia = {
            karta("2", "h", false, 2, 0), karta("3", "h", false, 3, 0), karta("4", "h", false, 4, 0), karta("5", "h", false, 5, 0), karta("6", "h", false, 6 ,0),
            karta("7", "h",false, 7, 0), karta("8", "h", false, 8, 0), karta("9", "h", false, 9, 0), karta("10", "h", false, 10, 0), karta("J", "h", false, 11, 0), 
            karta("Q", "h", false, 12, 0), karta("K", "h", false, 13, 0), karta("A", "h", false, 1, 0), 
            karta("2", "d", false, 2, 0), karta("3", "d", false, 3, 0), karta("4", "d", false, 4, 0), karta("5", "d", false, 5, 0), karta("6", "d", false, 6, 0), 
            karta("7", "d", false, 7, 0), karta("8", "d", false, 8, 0), karta("9", "d", false, 9, 0), karta("10", "d", false, 10, 0), karta("J", "d", false, 11, 0), 
            karta("Q", "d", false, 12, 0), karta("K", "d", false, 13, 0), karta("A", "d", false, 1, 0),
            karta("2", "s", false, 2, 1), karta("3", "s", false, 3, 1), karta("4", "s", false, 4, 1), karta("5", "s", false, 5, 1), karta("6", "s", false, 6, 1), 
            karta("7", "s", false, 7, 1), karta("8", "s", false, 8, 1), karta("9", "s", false, 9, 1), karta("10", "s", false, 10, 1), karta("J", "s", false, 11, 1), 
            karta("Q", "s", false, 12, 1), karta("K", "s", false, 13, 1), karta("A", "s", false, 1, 1),
            karta("2", "c", false, 2, 1), karta("3", "c", false, 3, 1), karta("4", "c", false, 4, 1), karta("5", "c", false, 5, 1), karta("6", "c", false, 6, 1), 
            karta("7", "c", false, 7, 1), karta("8", "c", false, 8, 1), karta("9", "c", false, 9, 1), karta("10", "c", false, 10, 1), karta("J", "c", false, 11, 1), 
            karta("Q", "c", false, 12, 1), karta("K", "c", false, 13, 1), karta("A", "c", false, 1, 1),
        };
        
    void tworz_kolejke(vector<karta> &talia){
            int card_ind = 0;
                for(int i=0; i<52; i++){
                card_ind = (rand()%talia.size());
                karta temp = talia.at(card_ind);
                talia.erase(talia.begin()+card_ind);
                kolejka.push(temp);
                }
    }

    void tworz_przewijanie(queue<karta> &talia, deque<karta> &przewijanie){
        for (int i = 0; i<24; i++){
                karta temp = talia.front();
            przewijanie.push_back(temp);
            talia.pop();
        }
        przewijanie[0].czyOdkryta=true;
        przewijanie[1].czyOdkryta=true;
        przewijanie[2].czyOdkryta=true;
    }

    void tworz_vectory(){
        for (int i = 0; i < 7; i++) {
                vector<karta> kolumna;
                for (int j = 0; j <= i; j++) {
                    kolumna.push_back(kolejka.front());
                    kolejka.pop();
                }
                k_vec.push_back(kolumna);
            }
                    k_vec[0][k_vec[0].size()-1].czyOdkryta = true;
        k_vec[1][k_vec[1].size()-1].czyOdkryta = true;
        k_vec[2][k_vec[2].size()-1].czyOdkryta = true;
        k_vec[3][k_vec[3].size()-1].czyOdkryta = true;
        k_vec[4][k_vec[4].size()-1].czyOdkryta = true;
        k_vec[5][k_vec[5].size()-1].czyOdkryta = true;
        k_vec[6][k_vec[6].size()-1].czyOdkryta = true;
    }

    void piszMape(){
    for(int i =0 ; i < wysokosc; i++){
        for(int j = 0; j < szerokosc; j++){
            if(i == 0 || i == 4) cout << "-";
            else if(i == 1 || i == 3 || i==5) cout << " ";
            else if (i == 2){
                if(j == 5){
                    if(przewijanie.size()>=3){
                    cout << kartaString(przewijanie.at(przewijaniex)) << setw(3) << " ";
                    cout << kartaString(przewijanie.at(przewijaniey)) << setw(3) << " ";
                    cout << kartaString(przewijanie.at(przewijaniez)) << setw(3) << " ";
                    }
                    else if(przewijanie.size() == 2){
                        cout << kartaString(przewijanie.at(przewijaniex)) << setw(3) << " ";
                        cout << kartaString(przewijanie.at(przewijaniey)) << setw(3) << " ";
                        cout << kartaString(pusta) << setw(3) << " ";
                    }
                    else if(przewijanie.size() == 1){
                        cout << kartaString(przewijanie.at(przewijaniex)) << setw(3) << " ";
                        cout << kartaString(pusta) << setw(3) << " ";
                        cout << kartaString(pusta) << setw(3) << " ";
                    }
                    else if(przewijanie.size() == 0){
                        cout << kartaString(pusta) << setw(3) << " ";
                        cout << kartaString(pusta) << setw(3) << " ";
                        cout << kartaString(pusta) << setw(3) << " ";
                    }

                } 
                if(j == 25)cout << kartaString(s1.top());
                else if(j == 30) cout << kartaString(s2.top());
                else if (j==35) cout << kartaString(s3.top());
                else if(j==40) cout << kartaString(s4.top()); 
                else cout << " ";
            }
            else if(j%6 == 0 && j <= 43) cout << "|";
            else if(j % 3 == 0){
                if(j == 3){
                    if(i - 6 < k_vec[0].size()){
                        if(k_vec[0][i-6].czyOdkryta == true) cout <<setw(3)<< kartaString(k_vec[0][i-6]);
                        else cout << "===";
                    } 
                    else cout <<setw(3)<< " ";
                }
                else if(j == 9){
                    if(i - 6 < k_vec[1].size()){
                        if(k_vec[1][i-6].czyOdkryta == true) cout <<setw(3)<< kartaString(k_vec[1][i-6]);
                        else cout << "===";
                    }
                    else cout <<setw(3)<< " ";
                }
                else if(j == 15){
                    if(i - 6 < k_vec[2].size()){
                    if(k_vec[2][i-6].czyOdkryta == true) cout <<setw(3)<< kartaString(k_vec[2][i-6]);
                        else cout << "===";
                    }
                    else cout <<setw(3)<< " ";
                }
                else if(j == 21){
                    if(i - 6 < k_vec[3].size()){
                        if(k_vec[3][i-6].czyOdkryta == true) cout <<setw(3)<< kartaString(k_vec[3][i-6]);
                        else cout << "===";
                    }
                    else cout <<setw(3)<< " ";
                }
                else if(j == 27){
                    if(i - 6 < k_vec[4].size()){
                        if(k_vec[4][i-6].czyOdkryta == true) cout <<setw(3)<< kartaString(k_vec[4][i-6]);
                        else cout << "===";
                    }
                    else cout <<setw(3)<< " ";
                }
                else if(j == 33){
                    if(i - 6 < k_vec[5].size()){
                        if(k_vec[5][i-6].czyOdkryta == true) cout <<setw(3)<< kartaString(k_vec[5][i-6]);
                        else cout << "===";
                    }
                    else cout <<setw(3)<< " ";
                }
                else if(j == 39){
                    if(i - 6 < k_vec[6].size()){
                        if(k_vec[6][i-6].czyOdkryta == true) cout <<setw(3)<< kartaString(k_vec[6][i-6]);
                        else cout << "===";
                    }
                    else cout <<setw(3)<< " ";
                }
            }
            else cout << " ";
        }
        cout << endl;
    }
    }
    };

    int main(){       
        srand( time( NULL ) );
        game game;
        game.pasjans();
        return 0;
    }
