# Push Swap - Algorithme de Tri

## 📋 Table des matières
1. [Vue d'ensemble](#vue-densemble)
2. [Structures de données](#structures-de-données)
3. [Opérations disponibles](#opérations-disponibles)
4. [Algorithme principal](#algorithme-principal)
5. [Cas spéciaux (≤5 éléments)](#cas-spéciaux--5-éléments)
6. [Cas général (>5 éléments)](#cas-général--5-éléments)
7. [Critères de performance](#critères-de-performance)

---

## Vue d'ensemble

Push Swap est un algorithme qui trie une liste de nombres à l'aide de **deux piles (stacks)** et d'un ensemble limité d'opérations. L'objectif est de trier les éléments avec le **minimum d'opérations**.

### Concepte de base:
- **Stack A**: La pile source contenant les nombres à trier
- **Stack B**: La pile auxiliaire (initialement vide)
- **Objectif**: Trier Stack A en ordre croissant en utilisant que Stack B comme espace de travail

---

## Structures de données

### `t_node` - Nœud de liste chaînée doublement liée
```c
typedef struct s_node
{
	int				value;      // La valeur numérique du nœud
	int				index;      // Position du nœud dans la séquence triée (0 à n-1)
	int				cost_a;     // Coût pour atteindre ce nœud depuis le haut de Stack A
	int				cost_b;     // Coût pour atteindre ce nœud depuis le haut de Stack B
	struct s_node	*target;    // Pointeur vers le nœud cible dans l'autre stack
	struct s_node	*next;      // Pointeur au nœud suivant
	struct s_node	*prev;      // Pointeur au nœud précédent
}	t_node;
```

### `t_stack` - Structure de pile
```c
typedef struct s_stack
{
	t_node	*top;      // Pointeur au premier élément (haut de la pile)
	t_node	*bottom;   // Pointeur au dernier élément (bas de la pile)
	int		size;      // Nombre d'éléments dans la pile
}	t_stack;
```

---

## Opérations disponibles

Chaque opération est écrite sur l'output. Voici les 12 opérations:

| Opération | Symbole | Description |
|-----------|---------|-------------|
| **Swap A** | `sa` | Échange les 2 premiers éléments de Stack A |
| **Swap B** | `sb` | Échange les 2 premiers éléments de Stack B |
| **Swap Both** | `ss` | Effectue `sa` et `sb` simultanément |
| **Push A** | `pa` | Prend le premier élément de Stack B et le met sur Stack A |
| **Push B** | `pb` | Prend le premier élément de Stack A et le met sur Stack B |
| **Rotate A** | `ra` | Décale tous les éléments de Stack A vers le haut (le haut va au bas) |
| **Rotate B** | `rb` | Décale tous les éléments de Stack B vers le haut |
| **Rotate Both** | `rr` | Effectue `ra` et `rb` simultanément |
| **Reverse Rotate A** | `rra` | Décale tous les éléments de Stack A vers le bas (le bas va au haut) |
| **Reverse Rotate B** | `rrb` | Décale tous les éléments de Stack B vers le bas |
| **Reverse Rotate Both** | `rrr` | Effectue `rra` et `rrb` simultanément |

### Exemple visuel - Opérations sur Stack A:
```
Initial: [3, 1, 2]  (3 au haut)

sa (swap):
Result:  [1, 3, 2]  (les 2 premiers échangés)

ra (rotate):
Result:  [1, 2, 3]  (3 va au bas)

rra (reverse rotate):
Result:  [3, 1, 2]  (3 revient au haut)
```

---

## Algorithme principal

### Phase 1️⃣: Initialisation

**Étape 1 - Parsing des arguments**
- Vérifier que tous les arguments sont des nombres valides
- Vérifier qu'il n'y a pas de doublons
- Vérifier que les nombres sont dans la plage [INT_MIN, INT_MAX]

**Étape 2 - Attribution des index**
```
Entrée: [7, 2, 5, 1, 4]
Après indexation:
  - 1 (le plus petit) → index 0
  - 2 → index 1
  - 4 → index 2
  - 5 → index 3
  - 7 (le plus grand) → index 4

Chaque nœud garde sa valeur originale mais connaît sa position finale
```

### Phase 2️⃣: Sélection de l'algorithme

**Si size ≤ 5**: Utiliser `sort_small()` (voir section cas spéciaux)
**Si size > 5**: Utiliser `sort_big()` (voir section cas général)

---

## Cas spéciaux (≤5 éléments)

Pour les petites listes, on utilise des algorithmes optimisés explicites:

### Size 2:
```
Si a[0] > a[1]: sa (swap)
Sinon: déjà trié
```

### Size 3:
```
sort_three() - Cas d'analyse exhaustive:
  Si [2,0,1]: sa → ra
  Si [1,2,0]: rra
  Si [2,1,0]: sa → rra
  etc...
```

### Size 4-5:
```
1. Pousser les petits éléments dans Stack B
2. Récursif: Trier les 3 restants dans Stack A
3. Insérer intelligemment les éléments de B dans A
```

**Coût typique**: 3-8 opérations

---

## Cas général (>5 éléments)

### 🔷 Stratégie: Tri par Chunks

L'algorithme divise la liste en **chunks** (portions) et les traite stratégiquement.

#### Paramètres des chunks:
```
Pour ≤100 éléments:  chunks = 7
Pour >100 éléments:  chunks = 11

chunk_size = total_size / chunks
```

#### Exemple avec 100 éléments et 7 chunks:
```
chunk_size = 100 / 7 ≈ 14 éléments par chunk

Chunk 0: indices 0-14
Chunk 1: indices 14-28
Chunk 2: indices 28-42
Chunk 3: indices 42-57
Chunk 4: indices 57-71
Chunk 5: indices 71-85
Chunk 6: indices 85-99
```

---

### 📍 Étape 1: `push_chunks_to_b()` - Remplir Stack B

**Objectif**: Pousser tous les éléments du chunk courant dans Stack B de manière organisée

**Algorithme**:
```
Pour i = 0 à chunks-1:
  Pour chaque élément dans Stack A:
    Si son index ≤ (i * chunk_size):
      - rb (rotate B vers le bas, pour garder les petits éléments accessibles)
    Sinon si son index ≤ ((i+1) * chunk_size):
      - pb (pousser dans B)
    Sinon:
      - Passer au prochain élément
```

**Résultat**: 
- Stack A: contient les éléments des chunks non traités
- Stack B: contient tous les éléments du chunk courant, avec les plus petits au fond

**Coût**: ~N/2 rotations (optimisation pour accès rapide)

---

### 🎯 Étape 2: `push_back_to_a()` - Récupérer les éléments

**Objectif**: Pousser les éléments de Stack B vers Stack A dans l'ordre croissant

**Stratégie**: À chaque itération, trouver l'élément de B qui peut être poussé dans A avec le **coût minimum** (rotation + push)

**Pseudocode**:
```
Tant que Stack B n'est pas vide:
  Pour chaque élément dans B:
    1. Trouver son élément cible dans A (le plus petit élément > que lui)
    2. Calculer le coût total pour l'amener au haut de B et le placer dans A
       coût = mouvements_B + mouvements_A
    
  Sélectionner l'élément avec le coût minimum
  Effectuer les rotations nécessaires
  pb (pousser dans A)
```

**Fonction clé: `find_best_target()`**
```
Pour chaque élément dans B:
  Chercher dans A le plus petit élément PLUS GRAND que lui
  
Exemple:
  B = [30, 20, 10]
  A = [50, 45, 40, 35]
  
  Pour 30 dans B: cible = 35 dans A
  Pour 20 dans B: cible = 40 dans A
  Pour 10 dans B: cible = 35 dans A (le plus petit > 10)
```

**Calcul du coût**:
```
cost = distance_in_B + distance_in_A + (optimisation si rotations de direction opposée)

Exemple:
  - Élément au bas de B: 3 rotations (ou 1 reverse rotate)
  - Cible au milieu de A: 25 rotations
  - Coût total: 3 + 25 = 28
  
  Optimisation: Si besoin de rra et rb, utiliser rrr (simultané)
```

---

### 🏁 Étape 3: `final_rotation()` - Position finale

**Objectif**: Faire en sorte que le plus petit élément soit au haut de Stack A

**Algorithme**:
```
1. Trouver l'index du plus petit élément dans A
2. Si index ≤ size/2: utiliser ra (rotate)
3. Sinon: utiliser rra (reverse rotate)
```

**Exemple**:
```
Stack A = [3, 4, 5, 1, 2]  (supposons size=5)
Plus petit = 1 à index 3

Comme 3 > 5/2 (2.5):
  Utiliser rra 2 fois: [1, 2, 3, 4, 5] ✓
```

---

## Critères de performance

### Limites du projet:

| Taille | Limite d'opérations | Complexité |
|--------|--------------------|-----------| 
| 100 nombres | < 700 opérations | Optimization requise |
| 500 nombres | < 5500 opérations | Plus de flexibilité |

### Performance actuelle avec chunks=7:

```
100 nombres:  ~697 ops moyenne
  - Min: 589 ops
  - Max: 814 ops
  - Taux de réussite: ~80%

500 nombres:  ~4916 ops moyenne
  - Min: 4546 ops
  - Max: 5977 ops
  - Taux de réussite: ~90%
```

### Facteurs affectant la performance:

1. **Nombre de chunks**: Plus de chunks = meilleure sélection mais plus de complexité
2. **Stratégie de rotations**: Utiliser `rr`/`rrr` pour économiser des opérations
3. **Sélection du meilleur élément**: Minimiser le coût total de mouvement
4. **Distribution des données**: Certaines permutations aléatoires sont plus difficiles

---

## Fluxogramme complet

```
┌─────────────────────────┐
│  Lire arguments         │
│  Valider & indexer      │
└────────────┬────────────┘
             │
         size ≤ 5 ?
        /            \
      OUI             NON
      │               │
      ▼               ▼
  sort_small()   sort_big()
      │               │
      │        ┌──────┴──────┐
      │        │             │
      │        ▼             ▼
      │   push_chunks_ push_back_
      │   to_b()       to_a()
      │        │             │
      │        └──────┬──────┘
      │               │
      │        ┌──────▼──────┐
      │        │             │
      │        ▼             ▼
      │   final_   Output
      │   rotation() ops
      │        │             │
      └────────┴─────────────┘
             │
             ▼
        Stack A trié ✓
```

---

## Exemple complet: Tri de [3, 1, 2]

```
Initial State:
  Stack A: [3, 1, 2]  (3 au haut)
  Stack B: []

Étape 1: Indexation
  1 → index 0
  2 → index 1
  3 → index 2

Étape 2: size = 3, utiliser sort_small()

Étape 3: Appliquer sort_three()
  État: [3, 1, 2]
  1. Trouver le pattern → c'est [2, 0, 1]
  2. Appliquer: sa (swap 3 et 1)
     Résultat: [1, 3, 2]
  3. Appliquer: ra (rotate)
     Résultat: [3, 2, 1]
  4. Appliquer: sa (swap 3 et 2)
     Résultat: [2, 3, 1]
  5. Appliquer: rra (reverse rotate)
     Résultat: [1, 2, 3] ✓

Output: sa ra sa rra
```

---

## Optimisations clés

1. **Fusion d'opérations**: `ra + rb = rr` (économise 1 opération)
2. **Reverse operations**: `rra` au lieu de `ra` × (n-1) quand c'est plus court
3. **Chunk sizing**: Ajusté pour équilibrer coût de rotations vs sélection
4. **Index-based sorting**: Traiter les index plutôt que les valeurs directes

---

## Fichiers du projet

- `src/main.c`: Entrée, lecture arguments
- `src/algo/push_swap.c`: Dispatcher (small vs big)
- `src/algo/sort_small.c`: Tri pour ≤5 éléments
- `src/algo/sort_big.c`: Tri par chunks pour >5 éléments
- `src/algo/utils.c`: Fonctions utilitaires (calcul coût, etc.)
- `src/operation/*.c`: Implémentation des 12 opérations
- `src/parsing/init_stack.c`: Validation et indexation
- `src/utils/ft_split.c`: Séparation d'arguments
