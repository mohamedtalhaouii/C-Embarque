## **Plan du Contenu :**

* **[Introduction aux systèmes embarqués](#1-introduction-aux-systèmes-embarqués)**
* **[Types de données et registres](#2-types-de-données-et-registres)**
* **[Manipulation des bits](#3-manipulation-des-bits)**
* **[Mémoire et pointeurs en embarqué](#4-mémoire-et-pointeurs-en-embarqué)**
* **[Structure d’un programme C embarqué](#5-structure-dun-programme-c-embarqué)**
* **[Entrées/Sorties (GPIO)](#6-entrées-sorties-gpio)**
* **[Timers et interruptions](#7-timers-et-interruptions)**
* **[Communication série (UART, SPI, I2C)](#8-communication-série-uart-spi-i2c)**
* **[Optimisation et directives](#9-optimisation-et-directives)**
* **[Organisation modulaire du code](#10-organisation-modulaire-du-code)**

---

<h3 align="center"><a href="https://github.com/mohamedtalhaouii/Programmation-C" target="_blank">Lien de Programmation en Language C</a></h3>

---

## **1. Introduction aux systèmes embarqués**

* Systèmes embarqués = ordinateurs spécialisés intégrés.
* Langage C = proche du matériel, portable, efficace.
* Pas de système d’exploitation complet → boucle infinie.

---

## **2. Types de données et registres**

* Types fixes (`<stdint.h>`) : `uint8_t`, `uint16_t`, `uint32_t`.
* Déclaration registre mémoire :

```c
#define NOM_REGISTRE (*(volatile uint32_t*)ADRESSE)
```

* Utilisation du mot-clé `volatile` pour empêcher l’optimisation.

---

## **3. Manipulation des bits**

* Mettre un bit :

```c
REGISTRE |= (1 << n);
```

* Réinitialiser un bit :

```c
REGISTRE &= ~(1 << n);
```

* Inverser un bit :

```c
REGISTRE ^= (1 << n);
```

* Tester un bit :

```c
if (REGISTRE & (1 << n)) { ... }
```

---

## **4. Mémoire et pointeurs en embarqué**

* Déclaration pointeur vers adresse fixe :

```c
TYPE *ptr = (TYPE*)ADRESSE;
```

* Déférencement :

```c
*ptr = valeur;
```

* Utilisation obligatoire de `volatile` pour registres matériels.

---

## **5. Structure d’un programme C embarqué**

```c
#include "fichier.h"

int main(void) {
    initialisation();
    while(1) {
        // boucle infinie
    }
}
```

* Fonction `main()` jamais terminée.
* Pas de bibliothèque standard complète (`stdio.h` limité).

---

## **6. Entrées/Sorties (GPIO)**

* Configuration d’un port en entrée/sortie.
* Syntaxe typique :

```c
PERIPHERIQUE->REGISTRE = configuration;
PERIPHERIQUE->REGISTRE |= masque;
PERIPHERIQUE->REGISTRE &= ~masque;
```

---

## **7. Timers et interruptions**

* Déclaration d’une routine d’interruption :

```c
void NOM_IRQHandler(void) {
    // code ISR
}
```

* Activation d’un timer :

```c
TIMER->REGISTRE = valeur;
```

* Réinitialisation du flag d’interruption :

```c
TIMER->REGISTRE &= ~FLAG;
```

---

## **8. Communication série (UART, SPI, I2C)**

* **UART** :

```c
UART->DR = donnée;
while (!(UART->SR & FLAG));
```

* **SPI** :

```c
SPI->DR = donnée;
while (!(SPI->SR & FLAG));
```

* **I2C** :

```c
I2C->CR1 |= START;
I2C->DR = donnée;
```

---

## **9. Optimisation et directives**

* `volatile` : empêcher l’optimisation sur variables liées au matériel.
* `inline` : optimisation des fonctions courtes.
* `static` : portée limitée à un fichier.
* `#define` : constantes et registres.
* `#pragma` : directives spécifiques au compilateur.

---

## **10. Organisation modulaire du code**

* Fichiers `.h` : déclarations, définitions de registres.
* Fichiers `.c` : implémentations des fonctions.
* Structures pour représenter des périphériques :

```c
typedef struct {
    uint32_t REG1;
    uint32_t REG2;
    uint32_t REG3;
} PERIPHERIQUE_TypeDef;

#define PERIPHERIQUE ((PERIPHERIQUE_TypeDef*)ADRESSE_BASE)
```

---


---

<h3 align="center"> 🧑🏻‍💻 | Made By : <a href="https://github.com/mohamedtalhaouii" target="_blank">Mohamed Talhaoui</a></h3>

👉 Veux-tu que je développe encore plus chaque section (par ex. détailler tous les registres GPIO, UART, timers) comme dans une **documentation complète**, ou bien on garde ce format **compact de syntaxe** ?
