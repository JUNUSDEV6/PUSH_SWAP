*This project has been created as part of the 42 curriculum by yohanafi.*

# Push_Swap

## Description

**Push_Swap** est un algorithme de tri qui utilise deux piles (stack A et stack B) et un ensemble restreint d'opérations pour atteindre un objectif : **trier les nombres de la pile A en ordre croissant avec le nombre minimal de mouvements possible**.

### Objectif du Projet

Le projet push_swap met l'accent sur :
- **L'optimisation algorithmique** : minimiser le nombre d'opérations
- **La gestion de mémoire efficace** : structures de données adaptées
- **L'analyse de complexité** : O(n log n) pour les listes > 5 éléments
- **La résolution de problèmes** : approches différentes selon la taille de la liste

### Fonctionnement Général

Le programme prend une liste de nombres en entrée et affiche une séquence d'opérations qui, si exécutées sur la pile A, la trient en ordre croissant. Chaque opération effectue une transformation simple (swap, push, rotate) sur les piles.

## Instructions

### Prérequis

- Compilateur GCC ou Clang
- Make
- Système Unix/Linux ou macOS

### Compilation

```bash
# Compiler le projet principal
make

# Compiler avec le bonus (checker)
make bonus

# Nettoyer les fichiers objets et exécutables
make clean

# Nettoyer complètement
make fclean

# Recompiler
make re
```

### Utilisation

#### Tri basique
```bash
# Avec plusieurs arguments
./push_swap 3 1 4 1 5

# Avec un seul argument (nombres séparés par des espaces)
./push_swap "3 1 4 1 5"

# Avec nombres négatifs
./push_swap "-5 3 -2 4"
```

#### Bonus : Checker

Le bonus `checker` valide si une séquence d'opérations trie correctement la liste :

```bash
# Générer les opérations et vérifier avec le checker
./push_swap 3 1 4 1 5 | ./checker 3 1 4 1 5

# Affiche "OK" si la liste est triée, "KO" sinon
```

### Gestion des Erreurs

Le programme gère automatiquement :
- Arguments invalides ou manquants
- Nombres hors limites (INT_MIN à INT_MAX)
- Nombres dupliqués (affiche "Error")
- Formats d'entrée variés

Exemple avec erreur :
```bash
./push_swap 3 3 1 4
# Affiche: Error (nombres dupliqués)

./push_swap abc
# Affiche: Error (nombre invalide)
```

## Algorithme et Stratégie

### Les 11 Opérations Disponibles

Chaque opération effectue une transformation simple sur les piles :

**Opérations sur la pile A :**
- `sa` : Swap A - Échange les deux premiers éléments
- `ra` : Rotate A - Déplace le premier élément à la fin
- `rra` : Reverse Rotate A - Déplace le dernier élément au début

**Opérations sur la pile B :**
- `sb` : Swap B - Échange les deux premiers éléments
- `rb` : Rotate B - Déplace le premier élément à la fin
- `rrb` : Reverse Rotate B - Déplace le dernier élément au début

**Opérations Doubles (optimisation) :**
- `ss` : Sa + Sb simultanément
- `rr` : Ra + Rb simultanément
- `rrr` : Rra + Rrb simultanément

**Opérations de Poussée :**
- `pa` : Push A - Déplace le sommet de B vers A
- `pb` : Push B - Déplace le sommet de A vers B

### Stratégie d'Optimisation

L'algorithme utilise deux approches différentes selon la taille de l'entrée :

#### 1. Petites Listes (≤ 5 éléments)

Des solutions manuelles optimales pour chaque cas :

- **Taille 2** : 0 ou 1 opération (`sa` si nécessaire)
- **Taille 3** : Maximum 2 opérations (analyse des 3 premiers)
- **Taille 4** : Maximum 4 opérations (isolation du minimum + tri 3)
- **Taille 5** : Maximum 6 opérations (isolation de 2 minima + tri 3)

#### 2. Grandes Listes (> 5 éléments)

Stratégie par **chunks** avec optimisation des coûts :

1. **Attribution d'index** : Assigner la position finale de chaque élément
2. **Division en chunks** : Partitionner la liste en sections
3. **Poussée vers B** : Déplacer progressivement les chunks
4. **Repoussage optimal** : Sélectionner l'élément avec le coût minimum
5. **Coût calculé** : Distance minimale = distance_A + distance_B

## Structure du Projet

```
push_swap/
├── Makefile              # Compilation
├── README.md             # Cette documentation
├── include/
│   └── push_swap.h       # Définitions et structures
├── src/
│   ├── main.c            # Point d'entrée
│   ├── algo/
│   │   ├── sort_small.c  # Tri pour listes ≤ 5
│   │   ├── sort_big.c    # Tri pour listes > 5
│   │   └── utils.c       # Utilitaires algorithmiques
│   ├── operation/        # Implémentation des 11 opérations
│   ├── parsing/          # Parsing et validation
│   └── utils/            # Utilitaires généraux
└── bonus/
    ├── checker.c         # Validateur de solution
    └── [opérations_silencieuses]
```

## Exemple Pratique

### Entrée
```bash
./push_swap 3 1 4 1 5
```

### Processus (liste de 5 éléments)
```
Initial:  A: [3, 1, 4, 1, 5]  B: []

Trouver les 2 minima et les pousser:
  ra     → A: [1, 4, 1, 5, 3]  B: []
  pb     → A: [4, 1, 5, 3]     B: [1]
  pb     → A: [4, 5, 3]        B: [1, 1]

Trier les 3 restants:
  sa     → A: [5, 4, 3]
  rra    → A: [3, 5, 4]
  ...et continuer jusqu'au tri

Repousser depuis B:
  pa     → A: [1, 3, 4, 5]     B: [1]
  pa     → A: [1, 1, 3, 4, 5]  B: []

✓ Trié !
```

### Sortie
```
ra
pb
pb
sa
rra
...
pa
pa
```

## Complexité Algorithmique

| Taille | Approche | Complexité | Mouvements |
|--------|----------|-----------|-----------|
| ≤ 5 | Cas par cas | O(1) | ≤ 12 |
| > 5 | Chunks | O(n²) pire cas, ~O(n log n) moyen | Optimisé |

## Ressources et Utilisation d'IA

### Ressources Classiques

**Documentation et Références :**
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) - Wikipedia
- [Sorting Algorithms Overview](https://en.wikipedia.org/wiki/Sorting_algorithm) - Comparaison des algorithmes
- [Turk Algorithm](https://medium.com/@ayogun/push-swap-tutorial-fa746e6aba1e) - Stratégie optimisée pour grand ensembles

### Utilisation d'IA (GitHub Copilot)

**Tâches pour lesquelles l'IA a été utilisée :**

1. **Génération de la documentation README.md** (100%)
   - Structure et formatage du document
   - Explications claires des concepts
   - Exemples et diagrammes

2. **Correction de bugs de compilation** (50%)
   - Identification des erreurs de pointeurs
   - Suggestions de fixes pour `checker.c`
   - Vérification des signatures de fonction

3. **Conseils algorithmiques** (30%)
   - Explications des stratégies de tri
   - Approches pour optimiser les mouvements
   - Calcul des coûts de mouvement

**Parties du projet développées manuellement :**
- Implémentation complète de l'algorithme principal (src/algo/)
- Toutes les opérations de pile (src/operation/)
- Parsing et validation (src/parsing/)
- Structure de données et gestion mémoire

### Outils et Technologies

- **Langage** : C (norme 42)
- **Compilateur** : GCC/Clang avec flags `-Wall -Wextra -Werror`
- **Éditeur** : VS Code avec GitHub Copilot
- **Contrôle de version** : Git

---

**Date de création** : Décembre 2025  
**Auteur** : yohanafi (42 School)

---

## Flow Complet

```
┌─────────────────────────────────────────┐
│ ENTRÉE : Liste de nombres (en désordre)│
└─────────────┬───────────────────────────┘
              │
              ▼
┌─────────────────────────────────────────┐
│ 1. PARSING & INITIALISATION              │
│    - Vérifier validité des arguments    │
│    - Créer stack A avec les nombres    │
│    - Créer stack B vide                │
└─────────────┬───────────────────────────┘
              │
              ▼
┌─────────────────────────────────────────┐
│ 2. VÉRIFIER SI DÉJÀ TRIÉ                │
│    - Si oui : fin                      │
│    - Si non : continuer               │
└─────────────┬───────────────────────────┘
              │
              ▼
        ┌─────────────┐
        │ Taille ≤ 5? │
        └────┬────┬───┘
           OUI│   │NON
              │   │
    ┌─────────▼─┐ └────────────────────┐
    │ SORT SMALL│                      │
    │  Cas à    │              ┌───────▼────────┐
    │  cas      │              │  SORT_BIG      │
    └───────┬───┘              │  (Chunks)      │
            │                  └────────┬────────┘
            │                          │
            └──────────┬───────────────┘
                       │
                       ▼
┌─────────────────────────────────────────┐
│ 3. SORTIE                               │
│    - Affiche les opérations effectuées  │
│    - Stack A est maintenant triée      │
└─────────────────────────────────────────┘
```

---

## Exemple Pratique

### Entrée
```bash
./push_swap 3 1 4 1 5
```

### Processus (Taille = 5)
```
Initial:  A: [3, 1, 4, 1, 5]  B: []

Trouver le minimum : 1
Position : index 1

Déplacer le 1 au top :
  ra                A: [1, 4, 1, 5, 3]
  pb                A: [4, 1, 5, 3]     B: [1]

Trouver le prochain minimum : 1
  pb                A: [4, 5, 3]        B: [1, 1]

Trier les 3 restants :
  sa                A: [5, 4, 3]
  rra               A: [3, 5, 4]
  rra               A: [4, 3, 5]
  sa                A: [3, 4, 5]

Repousser les éléments de B :
  pa                A: [1, 3, 4, 5]     B: [1]
  pa                A: [1, 1, 3, 4, 5]  B: []

✓ Trié !
```

### Sortie
```
ra
pb
pb
sa
rra
rra
sa
pa
pa
```

---

## Complexité

- **Petites listes (≤5)** : O(1) - Cas spécifiques
- **Grandes listes** : O(n²) dans le pire cas, mais généralement proche de O(n log n) avec optimisation des chunks

La qualité du tri dépend fortement du choix de la taille des chunks et de l'optimisation du calcul des coûts.

---

## Compilation et Utilisation

```bash
# Compiler
make

# Utiliser
./push_swap 3 1 4 1 5

# Avec plusieurs arguments
./push_swap "3 1 4 1 5"

# Bonus : visualiseur
make bonus
./checker 3 1 4 1 5
```

---

## Gestion des Erreurs

Le programme gère :
- ✅ Arguments invalides
- ✅ Nombres hors limites (INT_MIN à INT_MAX)
- ✅ Nombres dupliqués
- ✅ Allocation mémoire
- ✅ Formats d'entrée variés

---

## Points Clés d'Optimisation

1. **Index** : Permet de comparer rapidement les positions finales
2. **Chunks** : Réduit le nombre de rotations nécessaires
3. **Coût minimum** : Sélectionne les mouvements les plus efficaces
4. **Chemin optimal** : Choisit entre rotate et reverse rotate
5. **Gestion des stacks** : Structures doublement chaînées pour efficacité

---

## Améliorations Futures

- [ ] Optimiser la taille des chunks dynamiquement
- [ ] Implémenter la stratégie Turk pour de meilleures performances
- [ ] Support pour les nombres très grands
- [ ] Parallelization des calculs de coût

---

**Auteur** : yohanafi (42 School)  
**Date** : 2025
