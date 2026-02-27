bool amigo(int x, int y) {
    //encontrar TODOS los divisores y sumarlos
    int acum = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            acum = i + acum;
        }
    }

    return (acum == y);

}