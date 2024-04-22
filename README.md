Maria Choix
Gautier Anagnostides
L1

Lien Github:

Dans ce projet il nous est demandé de créer une bibliothèque pour gérer des dataframes en mémoire. On cherche alors à
réaliser des structures bidimensionnelles où chaque colonne peut contenir des données de types entiers.

En premiers temps, la bibliothèque sera composée de deux fichiers d'en-tête : column.h et cdataframe.h.
Le premier fichier contient la structure pour représenter une colonne (exclusivement d'entiers pour faciliter la
réalisation) ainsi que les fonctions pour gérer cette colonne. En amont, l'ajout de fonctions qui font l'étude d'un
nombre x donné pzr rapport aux valeurs de la colonne, est un travail d'avantage long et fastidieux.
Le deuxième fichier contient la structure pour représenter un dataframe, un tableau de colonnes. On y ajoute des
fonctions utiles qui permettent l'alimentation, laffichage, les opérations usuelles, et l'analyse et statistiques
(pas encore fait). Il s'agit de prototypes mais sont toutes quasiment complètes.
Ainsi la bibliothèque fournit des fonctions pour initialiser et libérer la mémoire des colonnes et des dataframes, pour
ajouter des colonnes à un dataframe, pour accéder aux données d'une colonne à une position donnée, et pour imprimer le
contenu d'un dataframe.
Pour la répartition des tâches pour ce projet, nous avons décidé de confier à une première personne,Maria, la tâche de réaliser les fonctions du fichier column.h ainsi que le main, puis à la seconde, Gautier, de réaliser les fonctions du fichiers dataframe.h après que les premières aient été réalisées (car ces fonctions ont besoins de celles de la gestion d'une colonne). Nous nous sommes échangés les codes via Discord pour en discuter si un de nous deux rencontrait un problème.
Dans le fichier main, on a un exemple de scénario d'utilisation des fonctions prévues, qui montre d'abord comment créer
des colonnes (de taille 5 pour l'exemple soit 5 éléments pouvant être incrémentés), ajouter des valeurs (10 et 11 pour
l'exemple), accéder aux données d'une colonne à toutes positions et enfin supprimer une colonne. 

