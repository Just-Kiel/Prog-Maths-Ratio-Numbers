
# RAPPORT FINAL PROJET MATH-INFO & PROG

## INTRODUCTION
<br/>
<p>Dans ce rapport, Aurore Lafaurie et Sarah N’GOTTA vont vous présenter leur travail de recherche et de programmation sur les nombres rationnels. Dans une première partie, la présentation de leur classe de rationnels, les surcharges d’opérateurs associées et des travaux plus approfondis sur les approximations, conversions de rationnels, templatage de fonction… Dans une deuxième partie axée sur les mathématiques, elles exposeront des travaux de recherches sur des fonctions mathématiques non implémentées dans la partie programmation. Dans une troisième basée sur l’analyse, elles traiteront des tests unitaires. Enfin, une partie succincte concernant la partie programmation, elles présenteront un tableau des tâches réalisées.
</p>
<br/>
<br/>

## Nombre Rationnel
### Class
<br/>
<p>Nous avons codés une classe Ratio à partir des consignes du sujet. Nous avons modifié quelques points.
</p>
</br>
Les attributs de notre class sont donc : 
</br>
<ul>
    <li>le numérateur comme integer (int),
    <li>le dénominateur comme integer non signé (unsigned int)
</ul>
</br>
<p>Nous avons aussi envisagé d’ajouter un booléen permettant de savoir si le rationnel créé était approximé ou exact. Afin de coller au sujet, tous les rationnels générés ont un PGCD égal à 1 avec des méthodes de vérification.
</p>



>L'opérateur division : <br/><br/><font size="5">
$\frac{\frac{a}{b}}{\frac{c}{d}}$=$\frac{a}{b}$ x $\frac{d}{c}$=$\frac{ad}{bc}$</font>
<br/>
<br/>

<br/>






