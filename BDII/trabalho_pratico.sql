drop database if exists SistemaVendas;
create database if not exists SistemaVendas;
use SistemaVendas;

create table if not exists Cliente (
IdCliente int auto_increment,
    NomeCliente varchar(30) not null,
    Endereco varchar(30) not null,
    Cidade varchar(20) not null,
    Estado char(2) not null,
    Obs varchar(40),
    primary key (IdCliente)
);

create table if not exists Transportadora(
IdTransportadora int auto_increment,
    NomeTransportadora varchar(50) not null,
    Endereco varchar(30) not null,
    Cidade varchar(20) not null,
    Estado char(2) not null,
    Atividade varchar(20),
    primary key (IdTransportadora)
);

create table if not exists Produto(
IdProduto int auto_increment,
    NomeProduto varchar(50) not null,
    Descricao varchar(30) not null,
    Preco float not null,
    Quantidade int not null,
    primary key (IdProduto)
);

create table if not exists Pedido(
IdPedido int auto_increment,
    IdCliente int,
    IdTransportadora int,
    Data date not null,
    Obs varchar(20),
    foreign key (IdCliente) references Cliente (IdCliente),
    foreign key (IdTransportadora) references Transportadora (IdTransportadora),
    primary key (IdPedido)
);

create table if not exists OrdemPedido(
IdOrdemPedido int auto_increment,
    IdProduto int,
    IdPedido int,
    Quantidade int not null,
    foreign key (IdProduto) references Produto (IdProduto),
    foreign key (IdPedido) references Pedido (IdPedido),
    primary key (IdOrdemPedido)
);

INSERT INTO Cliente VALUES
(1, 'ANTON', 'R. TOON 23', 'Campinas', 'SP', NULL),
(2, 'Vicky', 'AV. 2 – 342', 'Campinas', 'SP', NULL),
(3, 'Kinnard', 'AV 5 - BL9', 'RIO DE JANEIRO', 'RJ', NULL),
(4, 'Steven', 'ASA NORTE - BL8 - 56', 'Brasília', 'DF', NULL),
(5, 'BROWN', 'R. 156 – 90', 'São Paulo', 'SP', NULL),
(6, 'SAM', 'R. 32 – 23', 'São Paulo', 'SP', NULL),
(7, 'BERGS', 'AV. NORTE SUL 456', 'Campinas', 'SP', NULL),
(8, 'AROUT', 'R. BERKAZEL 90', 'Porto Alegre', 'RS', NULL),
(9, 'LARRY', 'AV. UM 908', 'Campinas', 'SP', NULL),
(10, 'HARRISON', 'R. 23 -98', 'Belo Horizonte', 'MG', NULL);

-- Transportadoras
INSERT INTO Transportadora VALUES
(1, 'TRANSCAR S.A.', 'R. 13 DE MAIO 213', 'CAMPINAS', 'SP', NULL),
(2, 'CITY CAR', 'AV. 2 - 342', 'CAMPINAS', 'SP', NULL),
(3, 'TRANSPORTE JUND', 'AV 5 - BL9', 'RIO DE JANEIRO', 'RJ', NULL),
(4, 'SPEED S.A.', 'ASA NORTE - BL8 - 56', 'BRASILIA', 'DF', NULL),
(5, 'ALIENS TRANSPORTES', 'R. 156 - 90', 'SAO PAULO', 'SP', NULL);

-- Produtos
INSERT INTO Produto VALUES
(1, 'MK22', 'MAQUINA SERIE 23', 560.00, 200),
(2, 'SPMW34', 'ROLAMENTO SERIE3', 210.00, 50),
(3, 'FVG1', 'BLOCO 5 MAQUINA SP', 780.00, 10),
(4, 'SPEG234', 'SUPORTE MAQUINA R5', 300.00, 15),
(5, 'MKS34', 'MAQUINA SERIE 21A', 1250.00, 8),
(6, 'MKP22', 'MAQUINA SERIE 23C', 656.00, 20),
(7, 'SPMW34', 'ROLDANA SERIE 13', 910.00, 10),
(8, 'FVG1', 'BLOCO 4 MAQUINA SP3', 880.00, 10);

-- Pedidos
INSERT INTO Pedido VALUES
(1, 5, 1, '2004-10-25', NULL),
(2, 8, 3, '2004-10-02', NULL),
(3, 5, 1, '2004-04-25', NULL),
(4, 4, 1, '2004-10-02', NULL),
(5, 10, 2, '2004-04-02', NULL),
(6, 10, 5, '2004-04-08', NULL),
(7, 10, 1, '2004-10-08', NULL),
(8, 10, 2, '2004-10-25', NULL),
(9, 1, 1, '2004-10-25', NULL),
(10, 2, 3, '2004-05-03', NULL),
(11, 1, 1, '2004-04-26', NULL),
(12, 2, 1, '2004-08-02', NULL),
(13, 2, 5, '2004-04-15', NULL),
(14, 4, 5, '2004-08-08', NULL),
(15, 2, 1, '2004-05-08', NULL),
(16, 8, 2, '2004-05-25', NULL);

-- Ordens de Pedido
INSERT INTO OrdemPedido VALUES
(1, 5, 1, 15),
(2, 8, 1, 2),
(3, 5, 2, 25),
(4, 4, 3, 204),
(5, 1, 4, 424),
(6, 1, 5, 84),
(7, 8, 5, 80),
(8, 4, 6, 25),
(9, 1, 6, 21),
(10, 2, 7, 35),
(11, 1, 8, 26),
(12, 2, 9, 82),
(13, 2, 10, 42),
(14, 4, 11, 8),
(15, 6, 11, 14),
(16, 5, 12, 54),
(17, 4, 13, 12),
(18, 7, 14, 42),
(19, 7, 15, 44),
(20, 2, 15, 14),
(21, 1, 16, 20),
(22, 2, 16, 54),
(23, 3, 7, 32),
(24, 1, 8, 26),
(25, 2, 9, 80),
(26, 2, 10, 15),
(27, 4, 11, 20);

DELETE op FROM OrdemPedido AS op
JOIN Pedido AS p ON op.IdPedido = p.IdPedido
WHERE p.idCliente = 10 AND p.Data >= "2004-11-01";

UPDATE Pedido AS p
SET p.IdTransportadora = 4
WHERE p.Data >= "2004-04-01" AND p.Data < "2004-05-01" AND p.IdTransportadora = 5;

