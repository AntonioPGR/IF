class Dinossauro extends AnimalTamagotchi {

  public Dinossauro(String nome) {
    super(nome);
  }

  @Override
  public void comer() {
    fome = clamp(fome - 20);
    energia = clamp(energia + 10);
  }

  @Override
  public void dormir() {
    energia = clamp(energia + 30);
    felicidade = clamp(felicidade + 5);
  }

  @Override
  public void brincar() {
    felicidade = clamp(felicidade + 20);
    energia = clamp(energia - 15);
    fome = clamp(fome + 10);
  }

  @Override
  public void mostrar() {
    System.out.println("     🦖");
    System.out.println("    (•ᴗ•)");
    System.out.println("   /|   |\\");
    System.out.println("   / \\_/ \\");
    showStatus();
  }
}
