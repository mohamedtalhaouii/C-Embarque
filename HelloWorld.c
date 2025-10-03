#include "stm32f10x.h"   // Fichier d'en-tête du microcontrôleur (STM32F1)

int main(void) {
    // 1. Activer l’horloge du port GPIOC
    RCC->APB2ENR |= (1 << 4);

    // 2. Configurer PC13 en sortie (LED connectée sur certaines cartes)
    GPIOC->CRH &= ~(0xF << 20);   // Nettoyer la configuration du pin 13
    GPIOC->CRH |=  (0x1 << 20);   // Mettre en sortie Push-Pull

    // 3. Boucle infinie : allumer/éteindre la LED
    while (1) {
        GPIOC->ODR ^= (1 << 13);   // Inverser l’état du bit 13 (LED)
        
        // Petit délai (boucle vide)
        for (volatile int i = 0; i < 100000; i++);
    }
}
