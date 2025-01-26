
# **Comic Book Reader**

## **Table des matières**
1. [Introduction](#introduction)
2. [Fonctionnalités](#fonctionnalités)
3. [Installation](#installation)
4. [Utilisation](#utilisation)
5. [Contributeurs](#contributeurs)

## **Introduction**
**Comic Book Reader** est une application conçue pour les amateurs de bandes dessinées. Il peut lire et convertir des formats de fichiers populaires tels que .cbz, .cbr et .pdf, et prend également en charge la compression d'images aux formats cbz ou cbr. Il fournit également des fonctions telles que la lecture asynchrone et le basculement entre plusieurs modes de lecture.


## **Fonctionnalités**
- **Lecture multimédia** : Support des formats `.cbz`, `.cbr` et `.pdf`.
- **Affichage dynamique** : 
  - Mode double page.
  - Zoom avant/arrière.
  - Navigation intuitive entre les pages.
- **Création de fichiers** : Création de fichiers `.cbz` ou `.cbr` à partir d'images.
- **Filtrage d'image** : Application de filtres pour améliorer la lisibilité.
- **Interface intuitive** :
  - Chargement asynchrone des fichiers.
  - Support des raccourcis clavier et des gestes tactiles (si applicable).


## **Installation**

### **Prérequis**
- **Système d'exploitation** : Windows, macOS ou Linux.
- **Compilateur** : Compatible avec C++17.
- **Dépendances** :
  - [Qt 5](https://www.qt.io/)
  - [QuaZip](https://github.com/stachenov/quazip)
  - [Poppler](https://poppler.freedesktop.org/)
  - [unrar](https://www.rarlab.com/rar_add.htm)

### **Étapes d'installation**
1. **Cloner le projet** :
   ```bash
   git clone https://github.com/votre-repo/comic-book-reader.git
   cd comic-book-reader
   ```

2. **Configurer le projet avec CMake** :
   ```bash
   mkdir build && cd build
   cmake ..
   ```

3. **Compiler le projet** :
   ```bash
   make
   ```

4. **Exécuter l'application** :
   ```bash
   ./ComicBookReader
   ```


## **Utilisation**

### **Ouverture d’un fichier**
1. Cliquez sur le bouton **"Open"**.
2. Sélectionnez un fichier au format `.cbz`, `.cbr` ou `.pdf`.
3. Choisissez le mode d’affichage (simple ou double page).

### **Création d’un fichier**
1. Cliquez sur le bouton **"Create"**.
2. Sélectionnez les images à inclure.
3. Enregistrez votre fichier au format `.cbz` ou `.cbr`.

### **Commandes principales**
- **Zoom avant** : Cliquez sur le bouton **"+"**.
- **Zoom arrière** : Cliquez sur le bouton **"-"**.
- **Page suivante/précédente** : Utilisez les boutons **"Next"** et **"Previous"**.
- **Aller à une page spécifique** : Cliquez sur **"To Page"** et entrez le numéro de page.

---

## **Contributeurs**
- **Qizheng WANG** 
- **Xingzi ZHANG** 
