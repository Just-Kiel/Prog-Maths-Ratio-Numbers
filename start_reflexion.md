# Projet Programmation / Maths avec M.Nozick

## Avec Sarah N'Gotta

## TODO
### Ratio
- Numérateur (int) (represented as a)
- Dénominateur (uint) (represented as b)
- PGCD(a, b) = 1 -> std::gcd / a/PGCD and b/PGCD to obtain irreductible

- 0 = 0/1
- inf = 1/0

### Opérations
- Somme : $a \over b$ $+$ $c \over d$ $=$ $ad+bc \over bd$ 
- Produit : $a \over b$ $*$ $c \over d$ $=$ $ac \over bd$ 
- Inverse : $(\frac{a}{b})^{-1}$ $=$ $b \over a$ pour tout $b \ne 0$
- Formalisation de la division : $\frac{\frac{a}{b}}{\frac{c}{d}}$ = $\frac{a}{b} * invert(\frac{c}{d})$
- Moins unaire : $a = -a$
- Valeur absolue : $a = abs(a)$
- Partie entière : a.modulo(b)
- Produit real ratio et ratio real : $a*r$ or $r*a$ then PGCD
- Opérateurs de comparaison == : if $a==c$ and $b==d$
- Opérateurs de comparaison != : if $a!=c$ or $b!=d$
- Opérateurs de comparaison > : ?
- Opérateurs de comparaison < : ?
- Opérateurs de comparaison >= : ?
- Opérateurs de comparaison <= : ?
- Affichage avec opérateur << : ?
- Real to ratio : ?

#### Optionnel
- Cos : ?
- sqrt : ?
- pow : ?
- exp : ?
- ...
- Coder en template
- Classe en constexpr
- Variadics

### Real to ratio
Algo à rendre viable pour real < 0

D’après vous, à qui s’adresse la puissance −1 de la ligne 8 ou
bien la somme de la ligne 12 ?

### Other
- Répondre aux questions du sujet dans le rapport
- Batterie d'exemples pour l'utilisateur
- Tests unitaires pour chaque implémentation

### Archi
- CMake avec sous projets
- Readme.md
- Commentaires de code
- Documentation Doxygen
- Github avec commits réguliers

- Classes
- Polymorphisme
- Usage STL
- Exceptions
- Asserts
- Espaces de nommage

## Rapport
- Etat des lieux des problemes
- Répondre aux questions

### Tableau bilan prog
- demandés codés et fonctionnels
- demandés codés mais pas fonctionnels
- demandés mais pas codés
- pas demandés codés et fonctionnels
- pas demandés mais pas codés ou pas fonctionnels

## Difficultés possibles
- Convert real to rationnel (see algo, only viable for real >= 0)
- Répondre aux questions

## Priorités

## Questions
- On a besoin de répondre aux questions présentes dans le sujet ? Si oui comment ? -> Dans le rapport