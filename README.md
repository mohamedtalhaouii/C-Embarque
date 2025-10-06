## **Plan du Contenu :**

* **[Qu’est-ce qu’un système embarqué ?](#1-quest-ce-quun-système-embarqué-)**
* **[Pourquoi le langage C en embarqué ?](#2-pourquoi-le-langage-c-en-embarqué-)**
* **[Types de données utiles en embarqué](#3-types-de-données-utiles-en-embarqué)**
* **[Manipulation des registres et bits](#4-manipulation-des-registres-et-bits)**
* **[Pointeurs et mémoire](#5-pointeurs-et-mémoire)**
* **[Structure d’un programme C embarqué](#6-structure-dun-programme-c-embarqué)**
* **[Entrées/Sorties (GPIO)](#7-entréessorties-gpio)**
* **[Timers et interruptions](#8-timers-et-interruptions)**
* **[Communication série (UART, SPI, I2C)](#9-communication-série-uart-spi-i2c)**
* **[Bonnes pratiques en embarqué](#10-bonnes-pratiques-en-embarqué)**

---

<h3 align="center"><a href="https://github.com/mohamedtalhaouii/Programmation-C" target="_blank">Lien de Programmation en Language C</a></h3>

---

## **1. Qu’est-ce qu’un système embarqué ?**

* C’est un **mini-ordinateur intégré** dans un appareil (smartphone, voiture, montre connectée, robot).
* Contraintes : **peu de mémoire, consommation réduite, temps réel**.
* Pas de système d’exploitation complet (souvent pas de Linux/Windows).

---

## **2. Pourquoi le langage C en embarqué ?**

* Langage **rapide** (proche du matériel).
* Permet d’accéder **directement aux registres** du microcontrôleur.
* Portable (un même code peut s’adapter à plusieurs architectures).
* Utilisé dans presque **tous les microcontrôleurs** (ARM STM32, AVR Arduino, PIC, etc.).

---

## **3. Types de données utiles en embarqué**

👉 Utiliser des tailles **fixes** (bibliothèque `<stdint.h>`).

| Type       | Taille  | Exemple d’usage                     |
| ---------- | ------- | ----------------------------------- |
| `uint8_t`  | 8 bits  | lecture d’un GPIO                   |
| `uint16_t` | 16 bits | valeur d’un Timer                   |
| `uint32_t` | 32 bits | registres principaux                |
| `volatile` | —       | variable matérielle (non optimisée) |

---

## **4. Manipulation des registres et bits**

En embarqué, on doit activer/désactiver des **bits** spécifiques dans des registres.

* Mettre un bit :

```c
REG |= (1 << n);
```

* Effacer un bit :

```c
REG &= ~(1 << n);
```

* Inverser un bit :

```c
REG ^= (1 << n);
```

* Tester un bit :

```c
if (REG & (1 << n)) { ... }
```

---

## **5. Pointeurs et mémoire**

* Chaque périphérique est représenté par une **adresse mémoire**.
* On y accède avec des **pointeurs** :

```c
#define REGISTRE (*(volatile uint32_t*)ADRESSE)
```

* `volatile` = indispensable pour dire au compilateur que la valeur peut changer à tout moment (ex. interruption, capteur).

---

## **6. Structure d’un programme C embarqué**

Un programme embarqué suit toujours le même schéma :

```c
#include "microcontroller.h"

int main(void) {
    initialisation();   // horloge, GPIO, UART...
    while(1) {
        // Boucle infinie
    }
}
```

⚠️ La fonction `main()` **ne doit jamais se terminer**, car le programme doit tourner en continu.

---

## **7. Entrées/Sorties (GPIO)**

* **GPIO = General Purpose Input/Output**.
* Permet d’allumer une LED, lire un bouton, contrôler un capteur.
* Configuration typique :

```c
GPIO->DIR = ... ;   // Direction (entrée ou sortie)
GPIO->ODR = ... ;   // Écriture
GPIO->IDR = ... ;   // Lecture
```

---

## **8. Timers et interruptions**

* Les **timers** créent des délais précis ou des signaux (PWM).
* Les **interruptions (ISR)** permettent de réagir à un événement externe (bouton, capteur).
  Syntaxe générique :

```c
void NOM_IRQHandler(void) {
    // Code exécuté quand l’interruption se déclenche
}
```

---

## **9. Communication série (UART, SPI, I2C)**

* **UART** : communication simple TX/RX (ex. liaison PC ↔ microcontrôleur).
* **I2C** : bus à 2 fils maître-esclave (capteurs, mémoire).
* **SPI** : communication rapide maître-esclave (écrans, mémoire Flash).

Syntaxe générale :

```c
UART->DR = donnée;    // Envoi UART
SPI->DR = donnée;     // Envoi SPI
I2C->DR = donnée;     // Envoi I2C
```

---

## **10. Bonnes pratiques en embarqué**

* Toujours utiliser `volatile` pour registres et variables liées au matériel.
* Éviter l’utilisation de `malloc/free` (risque de fragmentation mémoire).
* Privilégier des **fonctions courtes** et optimisées.
* Organiser le projet en **fichiers `.h` et `.c`** pour séparer déclaration et implémentation.
* Toujours vérifier les **datasheets** du microcontrôleur (chaque registre est documenté).

---

<h3 align="center"> 🧑🏻‍💻 | Made By : <a href="https://github.com/mohamedtalhaouii" target="_blank">Mohamed Talhaoui</a></h3>
