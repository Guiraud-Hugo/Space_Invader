    Rapport de projet Hugo Guiraud

Tout d'abord, voici le lien conduisant à mon dépôt git contenant les sources de mon projet:
    https://github.com/Guiraud-Hugo/Space_Invader

Pour jouer à ce Space Invader, il faut :

    -Disposer d'une carte STM32 Discovery 
    -Branche les deux ports MiniUSB de la carte à l'ordinateur
    -Ouvrir un terminal
    -Lancer le screen (screen /dev/ttyUSB0 115200)
    -Ouvrir le projet sur AtollicTrueSTUDIO
    -Sauvegarder (Ctrl+Shift+s) et build (Btrl+b) 
    -Lancer le debug(F11)
    -Une fois le debug fini, cliquer sur "Resume" (F8)
    -Enfin, retourner sur le terminal et amusez-vous

Et pour ce qui est des touches à connaitre, je vous laisse lancer le jeu, tout à été prévu.

Lors de la programmation de ce projet, la simpicité n'a pas été mot d'ordre tout du long, voici quelques unes des difficultés rencontrées:

    -La première à été le déplacement des vaisseaux (le mien comme celui des ennemis).
        -Pour mon vaisseau, la maitrise de la fonction "serial_get_last_char()". J'ai eu du mal à comprendre le fait que cette fonction ne pouvait être utilisée qu'une seule fois pas boucle.
    J'ai donc dû stocker le résultat dans une variable (que j'ai nommé 'carac') et c'est cette variable qui a été utilisée à multiples reprises.       
        -Pour les vaisseaux adverses, j'avait créé une foction (avec un 'for') qui affichait tous les vaiseaux adverses. 
    Malheureusement, lorsqu'il a fallut faire leur déplacement, je me suis rendu compte que ça allait être très compliqué, et d'autant plus avec les tirs et les Hitbox de mes missiles.
    J'ai donc dû créer les vaisseaux ennemis un par un et réduire leur nombre afin de faire quelque chose de plus fluide (bien que..)
    
    -Le deuxième à été l'utilisation des pointeurs dans mes diverses fonctions. 
        En effet, ayant un expérience réduite dans la programmation, l'utilisation des pointeurs a été laborieuse (sur le début). Etant une notion théorique peu compliqué à comprendre,l'application à été plus compliquée. L'utilisation de l'esperluette (&) et de l'étoile (*) était mitigée pour moi. A force de pratique, j'ai réussi à résoudre tous les problèmes de pointeurs.

    -Enfin, la toisième difficulté que j'ai rencontrée est la lisibilité du code. 
        Ce problème est lié au fait que j'avait mis toutes mes fonction sur le même fichier. Donc dés que j'avais besoin de modifier une partie de mes fonctions, la première épreuve étaitde la trouver, et après de la débugger. J'ai donc créé différents fichers de codes sources'.c' et des headers '.h'afin de répatir ces fonctions et de les trouver plus facilement. Le débug et la recherche de problème à donc été plus pratique par le suite.

Pour ce qui est de la liste des notions apptises et/ou pofinées pendant ce projet, je dois dirre que toutes celles présent dans mes fichiers font partie de cette liste. Je n'avais que des les débuts des base de C, j'ai donc appris tout ça pendant votre cours et mis en pratique pendant le projet. Je peux quand même dire que les pointeur et l'utilisation des fichier sources et des headers sont des notion qui sont désormé des notions que je pense maitriser étant donné que ce sont des difficultés sur lesquelles j'ai buté et comme dit l'expression, "on apprend de ses erreurs".

Il y a une chose sur laquelle je souhaiterais avoir un retour : c'est l'utilisation des pointeurs et plus particulièrement du pointeur d'un pointeur.
   Je souhaiterais savoir si il est judicieusement utilisé et si il y avait plus simple à faire.

Mon Retour d'expérience de ce projet est rès positif pour ma part. 
    "On apprend mieux en s'amusant" est un diction que j'ai pu confirmer avec ce projet. En effet, j'ai trouver le résultat final très encourageant et concrêt ce qui m'a donné envie de m'y mettre. Le fait de programmer un Space Invader et très amusant et attrayant et j'y ai pris beaucoup de plaisir. Du plus votre pédagogie et votre disponibilité ont aussi beaucoup aidé dans la réalisation et l'accéssiblité de ce projet. Le langage C a aussi été une découverte pour moi et je pense avoir fait quelque chose de convenanble ppur un débutant. 

Conclusion : Pour ma part, beaucoup de positif pour ce projet.
    











