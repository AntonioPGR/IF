class Cachorro extends AnimalTamagotchi {

  public Cachorro(String nome) {
    super(nome);
  }

  @Override
  public void comer() {
    fome = clamp(fome - 25);
    energia = clamp(energia + 5);
  }

  @Override
  public void dormir() {
    energia = clamp(energia + 40);
  }

  @Override
  public void brincar() {
    felicidade = clamp(felicidade + 25);
    energia = clamp(energia - 20);
    fome = clamp(fome + 15);
  }

  @Override
  public void mostrar() {
    System.out.println("   🐶");
    System.out.println("  (ᵔᴥᵔ)");
    System.out.println("  /| |\\");
    System.out.println("   | |");
    showStatus();
  }
}
