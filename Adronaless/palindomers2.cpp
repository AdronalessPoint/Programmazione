#include <vector>
#include <iostream>

auto richiedi_cifra(std::vector<int> vect){  //funzione che ti chiede tramite un ciclo while le cifre del numero che vuoi sapere se sia palindromo o no finchè non premi ctrl D;
  std::cout << "Inserisci le cifre del numero (l'ordine non importa se è palindromo ;), premere ctrl+D per smettere di inserire le cifre " << '\n';
  
 for (double d; std::cin >>d;)
  {
    vect.push_back(d);
  }

  
  return vect;//ti ridà il vettore riempito
}


bool is_palindromo(std::vector<int> vect){ //funzione che decide se  è palindromo o no
  bool k;//è il booleano del risultato
  int i = 0;
  int n = vect.size();
  for (; i != n && vect[i]==vect[n-i-1]; ++i) {
}
  if (i==n) { //in base a se il while è arrivato in fondo (cioè se è stato interrotto dalla condizione sulla i) o no assegno il valore a k di "vero" se è palindromo, di "falso" altrimenti
      k= true;
  }
  else {
      k=false;
      }
  return k;
}

int main (){
    std::vector<int> vect{}; 
vect =richiedi_cifra(vect); //vect è un vettore, ora pieno

if(is_palindromo (vect)) {std::cout<< "è palindromo";}
else {std::cout<< "Non è palindromo";}
std::cout<< '\n';
}


