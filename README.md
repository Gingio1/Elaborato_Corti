# Progetto Note Manager

Progetto sviluppato in **C++** per il corso di **Laboratorio di Programmazione**.

L’obiettivo del progetto è realizzare un **gestore di note** da linea di comando (CLI), che consenta di creare, modificare e organizzare note testuali, applicando correttamente i principi di programmazione ad oggetti e il **pattern Observer**.

---

## 📝 Descrizione generale

Il sistema permette di gestire una collezione di note, ognuna caratterizzata da:
- un identificativo univoco
- un titolo
- un testo
- uno stato di blocco
- uno stato di preferito

Le note sono gestite all’interno di un contenitore (`Folder`) che fornisce tutte le operazioni principali.

Il progetto è strutturato in modo modulare e separa:
- **logica applicativa**
- **interfaccia utente**
- **test**

---

## 🧩 Pattern Observer

Il progetto utilizza il **pattern Observer** per notificare automaticamente i cambiamenti di stato del contenitore di note.

- `Subject` definisce l’interfaccia del soggetto osservabile
- `Observer` definisce l’interfaccia degli osservatori
- `Folder` implementa `Subject`
- `ConcreteObserver` implementa `Observer`

Ogni volta che viene aggiunta o rimossa una nota, il `Folder` notifica gli osservatori registrati.

Questo approccio permette di mantenere **disaccoppiata** la logica di gestione delle note dalle azioni eseguite in risposta ai cambiamenti.

---

## 📂 Struttura del progetto
---Elaborato_Corti/ ├── src/ │   ├── main.cpp │   ├── folder.h │   ├── folder.cpp │   ├── note.h │   ├── note.cpp │   ├── Observer.h │   ├── Subject.h │   ├── ConcreteObserver.h │   └── ConcreteObserver.cpp ├── tst/ │   ├── test_note.cpp │   └── test_folder.cpp ├── CMakeLists.txt └── README.md
## ⚙️ Compilazione e build

### Requisiti
- Compilatore C++ compatibile con **C++20**
- **CMake ≥ 3.16**
- CLion (consigliato)

### Build con CLion
1. Aprire la cartella del progetto
2. Attendere il caricamento di CMake
3. Selezionare il target `Elaborato_Corti`
4. Avviare l’esecuzione

### 🖥️ Utilizzo dell’applicazione

All’avvio viene mostrato un menu testuale che consente di:   
-aggiungere una nota  
-visualizzare l’elenco delle note                    
-visualizzare una singola nota   
-modificare titolo o contenuto  
-eliminare una nota     
-bloccare / sbloccare una nota
-aggiungere / rimuovere una nota dai preferiti   
-cercare note tramite parola chiave
-visualizzare le note preferite  
Le note bloccate non possono essere modificate.