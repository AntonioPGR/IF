/*create database Biblioteca;
use Biblioteca;

create table Editora (codigo int, nome varchar(30), contato varchar(20), primary key (codigo));
insert into Editora values (1, "Nova", "Ana"), (2,"Atual", Null), (3,"Moderna",null);
select * from Editora;

create table autores (codigo int, nome varchar(30), nacionalidade varchar(30), primary key (codigo));
insert into autores values (1, "Luiz", null), (2,"Antonio", null), (3, "Laura", null);
update autores set codigo= 10 where codigo = 1; 
update autores set codigo= 11 where codigo = 2;
update autores set codigo= 12 where codigo = 3;
select * from autores;

create table Livros (codigo int, titulo varchar(40), edicao int, genero varchar(30), anoPublicacao int, codigoEditora int, primary key (codigo), foreign key (codigoEditora) references Editora (codigo));
insert into Livros values (1, "A Terra", 1, "Romance", 2020, 1), (2, "A Lua", 1, "Terror", 2020, 1), (3, "O Mar", 1, null, 2020, 3);

create table Funcionarios ( cpf char(7), nome varchar(30), funcao  varchar(20), salario double, primary key(cpf));
insert into Funcionarios values ("345.678", "Beatriz", "Recepcionista", 2000.00), ("044.033","Sílvia","DBA", 1000.00), ("098.890", "Maria", "TI", 1500.00); 

create table retiraFuncionario ( cpfFuncionario char(7), codigoLivro int, primary key (cpfFuncionario, codigoLivro), foreign key (cpfFuncionario) references Funcionarios (cpf), foreign key (codigoLivro) references Livros (codigo));
insert into retiraFuncionario values ( "044.033", 1), ("345.678", 1), ("345.678", 3);

create table Usuarios (cpf char(7), nome varchar(30), endereco varchar(30), telefone varchar(12), codigoLivro int, primary key (cpf), foreign key (codigoLivro) references Livros (codigo));
insert into Usuarios values ("123.456", "Ana", "Rua A, 10", "3712-1010", 1), ("789.999", "Maria", "Rua WJ,30", "3722-2020", 1), ("876.985", "José", "Rua Dois, 33","3713-9090", 2);

create table Retirar (cpf char(7), codigoLivro int, primary key(cpf, codigoLivro), foreign key (cpf) references Usuarios (cpf), foreign key (codigoLivro) references Livros (codigo));
insert into Retirar values ("123.456", 1),("789.999", 1), ("789.999",3);

create table escreve (codigoLivro int, codigoAutor int, primary key(codigoLivro, codigoAutor), foreign key(codigoLivro) references Livros (codigo), foreign key (codigoAutor) references Autores (codigo));
insert into escreve values (1, 12), (1, 10),(3, 10);
*/
/* ----------------------------------------------------------------------- */

/* 1 - I */
CREATE VIEW LivrosRetirados AS
SELECT DISTINCT Funcionarios.nome, Livros.titulo 
FROM retiraFuncionarios
JOIN Funcionarios ON retiraFuncionarios.cpfFuncionario = Funcionarios.cpf
JOIN Livros On retiraFuncionarios.codigoLivro = Livros.codigo;
