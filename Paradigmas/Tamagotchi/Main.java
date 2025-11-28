
import java.util.List;

class Main{

  public static void main (String[] args){
    List<AnimalTamagotchi> animais = List.of(
      new Pikachu("Pikachu"),
      new Cachorro("Rex"),
      new Dinossauro("Dino")
    );

    animais.get(0).brincar();
    animais.get(0).comer();
    animais.get(1).brincar();
    animais.get(2).dormir();

    for (AnimalTamagotchi animal : animais) {
      animal.mostrar();
    }
  }

}