abstract class AnimalTamagotchi{

  String nome;
  Integer fome;
  Integer energia;
  Integer felicidade;

  public AnimalTamagotchi(String nome){
    this.nome = nome;
    this.fome = 50;
    this.energia = 50;
    this.felicidade = 50;
  }

  public void showStatus(){
    System.out.println("Nome: " + this.nome);
    System.out.println("Fome: " + this.fome);
    System.out.println("Energia: " + this.energia);
    System.out.println("Felicidade: " + this.felicidade);
  }

  protected int clamp(int valor) {
    return Math.max(0, Math.min(100, valor));
  }

  public abstract void mostrar();
  public abstract void comer();
  public abstract void dormir();
  public abstract void brincar();


}