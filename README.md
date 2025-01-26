
# **Comic Book Reader**

## **Table des matières**
1. [Introduction](#introduction)
2. [Fonctionnalités](#fonctionnalités)
3. [Installation](#installation)
4. [Affichage de UI](#affichage-de-UI)
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


## **Affichage de UI**

![Affichage de l'interface](./path_to_interface_image.png)


## **Contributeurs**
- **Qizheng WANG** 
- **Xingzi ZHANG**

