class Pikachu extends AnimalTamagotchi {

  public Pikachu(String nome) {
    super(nome);
  }

  @Override
  public void comer() {
    fome = clamp(fome - 15);
    energia = clamp(energia + 20);
    felicidade = clamp(felicidade + 5);
  }

  @Override
  public void dormir() {
    energia = clamp(energia + 35);
  }

  @Override
  public void brincar() {
    felicidade = clamp(felicidade + 30);
    energia = clamp(energia - 20);
    fome = clamp(fome + 10);
  }

  @Override
  public void mostrar() {
    System.out.println("   ⚡⚡ Pikachu! ⚡⚡");
    System.out.println("     (\\__/)");
    System.out.println("     (•ᴗ• )ノ⚡");
    System.out.println("    / >⚡  \\");
    showStatus();
  }
}
