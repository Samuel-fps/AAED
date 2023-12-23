/*
template <typename T> void mostrarPila(Pila<T> pila);
template <typename T> Pila<T> vector2pila(std::vector<T> v);

template <typename T>
void mostrarPila(Pila<T> pila){
    std::cout << "[ ";
    while(!pila.vacia()){
        std::cout << pila.tope() << " ";
        pila.pop();
    }
    std::cout << "]" << std::endl;
}

template <typename T>
Pila<T> vector2pila(std::vector<T> v){
    Pila<T> aux;
    
    for(size_t i = v.size() ; i > 0 ; --i)
        aux.push(v[i-1]);

    return aux;
}
*/