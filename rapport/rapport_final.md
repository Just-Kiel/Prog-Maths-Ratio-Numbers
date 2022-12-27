
# RAPPORT FINAL PROJET MATH-INFO & PROG

## I. INTRODUCTION
<br/>
<p>Dans ce rapport, Aurore Lafaurie et Sarah N’GOTTA vont vous présenter leur travail de recherche et de programmation sur les nombres rationnels. Dans une première partie, la présentation de leur classe de rationnels, les surcharges d’opérateurs associées et des travaux plus approfondis sur les approximations, conversions de rationnels, templatage de fonction… Dans une deuxième partie axée sur les mathématiques, elles exposeront des travaux de recherches sur des fonctions mathématiques non implémentées dans la partie programmation. Dans une troisième basée sur l’analyse, elles traiteront des tests unitaires. Enfin, une partie succincte concernant la partie programmation, elles présenteront un tableau des tâches réalisées.
</p>
<br/>

## II. Nombre Rationnel
### A. Classe

<p>Nous avons codé une classe Ratio à partir des consignes du sujet. Nous avons modifié quelques points.
</p>
Les attributs de notre class sont donc : 
</br>
<ul>
    <li>le numérateur comme integer (int),
    <li>le dénominateur comme integer non signé (unsigned int)
</ul>

<p>Nous avons aussi envisagé d’ajouter un booléen permettant de savoir si le rationnel créé était approximé ou exact. Afin de coller au sujet, tous les rationnels générés ont un PGCD égal à 1 avec des méthodes de vérification.
</p>

### B. Opérateurs
**1. Somme**

$\frac{a}{b}+\frac{c}{d}=\frac{ad+cb}{cd}$

<u>WARNING</u> : ne pas avoir de dénominateur égal à 0
<br/>
<br/>

**2. Soustraction**

$\frac{a}{b}+(-\frac{c}{d})=\frac{ad+(-c)b}{cd}$

<u>WARNING</u> : ne pas avoir de dénominateur égal à 0, on utilise l’opérateur rationnel + et le moins unaire -
<br/>
<br/>

**3. Moins Unaire**

$-(\frac{a}{b})=\frac{-a}{b}$

<u>WARNING</u> : ne pas avoir de dénominateur égal à 0
<br/>
<br/>

**4. Produit**

$\frac{a}{b}*\frac{c}{d}=\frac{ac}{bd}$

<u>WARNING</u> : ne pas avoir de dénominateur égal à 0
<br/>
<br/>

**5. Inverse**

$(\frac{a}{b})^{-1}=\frac{b}{a}$

<u>WARNING</u> : ne pas avoir de dénominateur égal à 0
<br/>
<br/>

**6. Division**

$\frac{\frac{a}{b}}{\frac{c}{d}}=\frac{a}{b}*\frac{d}{c}=\frac{a}{b}*inverse(\frac{c}{d})=\frac{ad}{bc}$	

<u>WARNING</u> : ne pas avoir de dénominateur égal à 0, on va utiliser l’opérateur d’inverse vu précédemment. Dans les tests unitaires on testera deux méthodes, utiliser l’opérateur inverse surchargé pour les ratios et le produit classique en faisant l’inversion nous-même.
Une exception est donc renvoyée si le ratio à diviser est divisé par le rationnel 0. L’opérateur puissance acceptant les puissance négative, on peut également calculer un inverse, une division avec la fonction puissance (^-1) .
<br/>
<br/>

**7. Valeur Absolue**

$\frac{a}{b}=\frac{a}{b}$ ou $\frac{-a}{b} = \frac{a}{b}$

<u>WARNING</u> : ne pas avoir de dénominateur égal à 0, on utilise l’opérateur abs de base prévu dans la librairie cmath. 
<br/>
<br/>

***8. Partie Entière***

$\frac{a}{b}=int(\frac{a}{b})$

<u>WARNING</u> : ne pas avoir de dénominateur égal à 0, bien penser à faire un static_cast < int > du dénominateur afin de pouvoir faire l’opération.
<br/>
<br/>

***9. Puissance***

$(\frac{a}{b})^k=\frac{a^k}{b^k}$

<u>WARNING</u> :  ne pas avoir de dénominateur égal à 0, on va également surcharger cet opérateur uniquement pour les puissances entières et non pour les puissances rationnelles. Cependant, on a pensé à des opérateurs qui pourraient avoir besoin d’une surcharge de l’opérateur puissance valable pour des puissances rationnelles. C’est le cas de l’opérateur racine carrée.
<br/>
<br/>

***10. Racine Carrée***

$\sqrt{\frac{a}{b}}=\frac{\sqrt{a}}{\sqrt{b}}$

<u>WARNING</u> :  ne pas avoir de dénominateur égal à 0, on utilise l’opérateur sqrt de base prévu dans la librairie cmath. 

Ma piste d’analyse au sujet de l’opérateur racine carrée pour des nombres rationnels est que cet opérateur ne pourra pas fonctionner pour : 

* des nombres entiers qui mis sous racine carrée ne donne pas en résultat un nombre entier (ex : ne fonctionne pas pour sqrt(2) mais fonctionne pour sqrt(9)=3). Lorsque ça ne fonctionne pas, on ne pourra jamais obtenir de fraction entière, seulement des approximations. 

* une autre approche, serait de dire que l’opérateur ne fonctionnera pas sur les nombres premiers et nombres entiers décomposables en nombres premiers (ex : ne fonctionnera pas pour 2, 3 et 6. En effet, 2 et 3 sont des nombres premiers et 6=2*3, elles se décomposent en produit de nombre premier, passé sous racine, le résultat ne sera pas un nombre entier).

_Pour le moment la fonction d’approximation n’est pas implémentée. On aura donc un message d’erreur si le calcul comprend les exceptions précédentes._

Une autre façon de calculer la racine carrée d’un rationnel serait d’utiliser l’opérateur rationnel de puissance. Ainsi : $\sqrt{\frac{a}{b}}=(\frac{a}{b})^{\frac{1}{2}}$

Malheureusement, nous n’avons pas implémenté la fonction puissance pour qu’elle fonctionne avec des puissances rationnelles, uniquement avec des puissances entières.

Nous avons tout de même implémenté l’opérateur ainsi que réalisé les tests unitaires mais ces derniers ne fonctionnent que pour des racines de nombres entiers non premiers et donc la racine est un entier.
<br/>
<br/>

***11. Fonction d’affichage (<<)***

```
std::ostream& operator<<(std::ostream& os, const Ratio &r) ;
````
Ici, on va créer une surcharge d’opérateur sur un opérateur d’affichage et non un opérateur mathématiques. On va surcharger un opérateur de la librairie std ostream. Le paramètre os renvoie à ce qui va venir avant les <<, la surcharge << fait le lien entre le mot d’appel "coût" et notre choix d’affichage de rationnel. A savoir “cout”, le mot qui va permettre l’affichage de nos rationnels. Surcharger << nous permet de choisir la façon dont on va afficher nos rationnels à savoir : a/b ainsi que l’équivalent en nombre réel. Cette surcharge d’opérateur ne sera pas implémentée à l’intérieur de la classe car elle n’est pas une méthode propre à la classe, ce n’est pas un opérateur de type Ratio.
<br/>
<br/>

En plus des opérateurs explicités ci-dessus, nous avons également surchargé des opérateurs d’assignation comme +=, -=, *= et des opérateurs de type comparaison (/=, <, >, <=, >=) qui ont été templaté pour être utilisés avec autre chose que des rationnels.
</br>
</br>

### C. Approximation et Conversion
**1. Nombre approximé ou non**

Une bonne façon d’améliorer notre code serait de créer des fonctions d’approximation. L’une pourrait nous dire si le résultat d’un calcul est approximatif ou non et une autre qui pourrait approximer un résultat plutôt que de renvoyer une erreur. 
Par exemple, si l’on prend le cas de l’opérateur racine carré. Une telle fonction pourrait renvoyer un résultat approximatif de $\sqrt{2}$ en convertissant le résultat en float au lieu de renvoyer une erreur.
</br>
</br>

**2. Conversion réél-ratio**
a)
b)
c)
</br>
</br>

### D. Pour aller plus loin… Templetage et constexpr
</br>
Nous n’avons pas utilisé le constexpr car nous nous sommes retrouvées face à des problèmes à la compilation.
Pour ce qui est de l’utilisation du template par contre, nous l’avons employé dans de nombreuses méthodes et notamment celle de conversion d’un réel vers un rationnel afin de pouvoir convertir un entier ou un nombre décimal.

</br>
</br>

## III. Réflexion mathématique avancée non implémentée
### A. Cosinus & Sinus

Les seules valeurs rationnelles que puisse prendre le cosinus ou le sinus d’un angle rationnel sont 0 , 1 , -1, ${\frac{1}{2}}$ , ${-\frac{1}{2}}$ . Si on avait codé la surcharge de cet opérateur, on aurait dû spécifier des exceptions pour lesquelles l'usage de ces opérateurs n’était pas conseillé ou donner un résultat approximé.
</br>
</br>


|     | 0 | $\frac{\Pi}{6}$ | $\frac{\Pi}{4}$ | $\frac{\Pi}{3}$ | $\frac{\Pi}{2}$ | $\Pi$ |
|:---:|:-:|:---------------:|:---------------:|:---------------:|:---------------:|:-----:|
| sin | 0 |  $\frac{1}{2}$  |        -        |        -        |        1        |   -1  |
| cos | 1 |        -        |        -        |  $\frac{1}{2}$  |        0        |   0   |

</br>

### B. Exponentielle et logarithme
</br>
</br>

## IV. Analyse

### A. Les questions du sujet

</br>

**<span style="color: #fd6c9e">1. Dans quels cas les nombres rationnels sont-ils efficaces ? Dans quels cas ne le sont-ils pas ?</span>**

Les nombres rationnels sont efficaces si les nombres ne sont pas trop grands ou trop petits. En effet, les int et les unsigned int ne sont pas codés à l’infini et sont donc limités.
Ils sont aussi efficaces quand on doit représenter certains réels avec un nombre de décimales infini (par exemple $\frac{1}{3}$).

</br>

**<span style="color: #fd6c9e"> 2. D’une façon générale, on peut s’apercevoir que les grands nombres
(et le très petit nombre) se représentent assez mal avec notre classe de rationnels. Voyez-vous une explication à ça ?</span>**

Comme dit plus tôt, les très grands nombres ainsi que les très petits seront compliqués à gérer en l’état puisque les entiers sont codés sur un nombre de bits limité. On se retrouverait donc dans certains cas avec des numérateurs et des dénominateurs tellement grands qu’il serait impossible de les coder en integer et unsigned integer.

</br>

**<span style="color: #fd6c9e">3. Lorsque les opérations entre rationnels s'enchaînent, le numérateur et le dénominateur peuvent prendre des valeurs très grandes, voire dépasser la limite de représentation des entiers en C++. Voyez-vous des solutions ?</span>**

Pour éviter d’être limité dans la représentation d’entiers, on pourrait choisir d’utiliser des long int par exemple. Cela permettrait d’avoir plus de possibilités mais cela serait aussi largement plus demandeur en terme de mémoire. Il faudrait donc que le type de variable soit adaptatif à la situation.

Une autre solution aurait été de garder la partie entière d’un côté et de ne travailler qu’avec la partie décimale. Cela résoudrait une part du problème (pour les très grands nombres). Il faudrait pour cela avoir un attribut conservant la partie entière. Cela n’a pas été implémenté mais cela aurait pu être une solution.


</br>
</br>

## V. Programmation

[<span style="color: #fd6c9e">Cliquer ici pour aller sur la page Git du projet !</span> ](https://github.com/Just-Kiel/Prog-Maths-Ratio-Numbers)

</br>
</br>
A venir, le tableau des tâches
</br>
</br>

Pour que notre librairie soit facilement utilisable, nous avons réalisé un fichier d’exemple sur l’utilisation de cette dernière ainsi qu’une documentation Doxygen.
