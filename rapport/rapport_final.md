
# RAPPORT FINAL PROJET MATH-INFO & PROG

## I. INTRODUCTION
<br/>
<p>Dans ce rapport, Aurore Lafaurie et Sarah N’GOTTA vont vous présenter leur travail de recherche et de programmation sur les nombres rationnels. Dans une première partie, la présentation de leur classe de rationnels, les surcharges d’opérateurs associées et des travaux plus approfondis sur les approximations, conversions de rationnels, templatage de fonction… Dans une deuxième partie axée sur les mathématiques, elles exposeront des travaux de recherches sur des fonctions mathématiques non implémentées dans la partie programmation. Dans une troisième basée sur l’analyse, elles traiteront des tests unitaires. Enfin, une partie succincte concernant la partie programmation, elles présenteront un tableau des tâches réalisées.
</p>
<br/>

## II. Nombre Rationnel
### A. Class

<p>Nous avons codés une classe Ratio à partir des consignes du sujet. Nous avons modifié quelques points.
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
#### 1. Somme

$\frac{a}{b}+\frac{c}{d}=\frac{ad+cb}{cd}$

<strong>WARNING</strong> : ne pas avoir de dénominateur égal à 0

#### 2. Soustraction

$\frac{a}{b}+(-\frac{c}{d})=\frac{ad+(-c)b}{cd}$

<strong>WARNING</strong> : ne pas avoir de dénominateur égal à 0, on utilise l’opérateur rationnel + et le moins unaire -

#### 3. Moins Unaire

$-(\frac{a}{b})=\frac{-a}{b}$

<strong>WARNING</strong> : ne pas avoir de dénominateur égal à 0

#### 4. Produit

$\frac{a}{b}*\frac{c}{d}=\frac{ac}{bd}$

<strong>WARNING</strong> : ne pas avoir de dénominateur égal à 0

#### 5. Inverse

$(\frac{a}{b})(^-1)=\frac{b}{a}$


#### 6. Division
$\frac{\frac{x}{1}}{x - y}$	

#### 7. Valeur Absolue
#### 8. Partie Entière
#### 9. Puissance
#### 10. Racine Carrée




$\frac{\frac{a}{b}}{\frac{c}{d}}$=$\frac{a}{b}$ x $\frac{d}{c}$=$\frac{ad}{bc}$</font>
<br/>
<br/>

<br/>






