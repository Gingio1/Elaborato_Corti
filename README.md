# Progetto Note Manager

Questo progetto implementa un sistema di gestione delle note in **C++**, sviluppato per il corso di **Laboratorio di Programmazione**.

L’applicazione consente di creare, modificare e organizzare note testuali all’interno di una collezione, utilizzando il **pattern Observer** per notificare automaticamente i cambiamenti di stato.

---

## 1. Classe Note

La classe `Note` rappresenta una singola nota.

### Attributi
- `int id` : identificativo univoco della nota
- `std::string title` : titolo della nota
- `std::string text` : contenuto della nota
- `bool locked` : indica se la nota è bloccata
- `bool favorite` : indica se la nota è contrassegnata come preferita

### Metodi principali
- Costruttore: inizializza identificativo, titolo e contenuto
- `lock()` / `unlock()` : blocca o sblocca la nota
- `setTitle()` / `setText()` : modifica titolo o contenuto (se non bloccata)
- `setFavorite()` : imposta lo stato di preferito
- Metodi getter per accedere agli attributi

### Test
La classe `Note` è testata tramite **test unitari** per verificare:
- la corretta creazione della nota
- il comportamento in caso di blocco
- la modifica degli attributi

---

## 2. Classe Folder

La classe `Folder` gestisce un insieme di note e fornisce le operazioni principali.

### Gestione delle note
- `int addNote(const std::string&, const std::string&)`  
  Aggiunge una nuova nota e restituisce il suo identificativo
- `bool removeNote(int id)`  
  Rimuove una nota dato l’identificativo
- `std::optional<Note> getCopy(int id) const`  
  Restituisce una copia della nota
- `Note* getMutable(int id)`  
  Restituisce un puntatore alla nota modificabile
- `const std::vector<Note>& all() const`  
  Restituisce l’elenco completo delle note

### Modifica e ricerca
- `search(const std::string&)`  
  Ricerca le note contenenti una parola chiave nel titolo o nel testo
- `favorites()`  
  Restituisce l’elenco delle note preferite
- `locked()`  
  Restituisce l’elenco delle note bloccate

### Test
La classe `Folder` è testata per verificare:
- aggiunta e rimozione delle note
- corretto funzionamento della ricerca

---

## 3. Pattern Observer

Il **pattern Observer** è utilizzato per notificare automaticamente i cambiamenti nello stato del `Folder`.

### Classe Subject
Interfaccia astratta che definisce:
- `addObserver(Observer*)`
- `removeObserver(Observer*)`
- `notifyObservers()`

La classe `Folder` implementa questa interfaccia.

---

### Classe Observer
Interfaccia astratta che definisce:
- `update(const Folder&)`

Viene chiamata ogni volta che il `Subject` notifica un cambiamento.

---

### Classe ConcreteObserver
Implementazione concreta dell’Observer.

- Monitora il numero di note presenti in un `Folder`
- Stampa un messaggio ogni volta che una nota viene aggiunta o rimossa
- Può essere registrato o rimosso dinamicamente dal `Folder`

---

## 4. Interfaccia utente (CLI)

L’interazione con l’utente avviene tramite un **menu testuale** che consente di:
- aggiungere note
- visualizzare e modificare note
- bloccare o sbloccare note
- gestire i preferiti
- effettuare ricerche

La logica applicativa è separata dall’interfaccia utente.

---

## 5. Test

Il progetto include test unitari realizzati con **GoogleTest**, situati nella cartella `tst/`.

I test verificano il corretto comportamento delle classi principali (`Note` e `Folder`) in modo automatico.

---

## Autore

Elaborato realizzato da Giulio Corti
