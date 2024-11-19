#include <iostream>
#include <cmath>

// Définition des opérations
typedef double (*Operation)(double, double);

double addition(double a, double b) {
    return a + b;
}

double soustraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        std::cerr << "Erreur : division par zéro !" << std::endl;
        exit(1);
    }
    return a / b;
}

double puissance(double a, double b) {
    return pow(a, b);
}

typedef double (*OperationUnaire)(double);

double sinus(double a) {
    return sin(a);
}

double cosinus(double a) {
    return cos(a);
}

double tangente(double a) {
    return tan(a);
}

double logarithme(double a) {
    if (a <= 0) {
        std::cerr << "Erreur : logarithme d'un nombre non positif !" << std::endl;
        exit(1);
    }
    return log(a);
}

double exponentielle(double a) {
    return exp(a);
}

int main() {
    Operation operations[] = {addition, soustraction, multiplication, division, puissance};
    OperationUnaire operations_unaires[] = {sinus, cosinus, tangente, logarithme, exponentielle};

    int choix;
    double a, b, resultat;

    while (true) {
        std::cout << "Calculatrice avancée" << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "1. Addition" << std::endl;
        std::cout << "2. Soustraction" << std::endl;
        std::cout << "3. Multiplication" << std::endl;
        std::cout << "4. Division" << std::endl;
        std::cout << "5. Puissance" << std::endl;
        std::cout << "6. Sinus" << std::endl;
        std::cout << "7. Cosinus" << std::endl;
        std::cout << "8. Tangente" << std::endl;
        std::cout << "9. Logarithme" << std::endl;
        std::cout << "10. Exponentielle" << std::endl;
        std::cout << "11. Quitter" << std::endl;

        std::cout << "Entrez votre choix : ";
        std::cin >> choix;

        if (choix == 11) {
            break;
        }

        if (choix >= 1 && choix <= 5) {
            std::cout << "Entrez la première valeur : ";
            std::cin >> a;
            std::cout << "Entrez la deuxième valeur : ";
            std::cin >> b;

            resultat = operations[choix - 1](a, b);
        } else if (choix >= 6 && choix <= 10) {
            std::cout << "Entrez la valeur : ";
            std::cin >> a;

            resultat = operations_unaires[choix - 6](a);
        }

        std::cout << "Résultat : " << resultat << std::endl;
    }

    return 0;
}