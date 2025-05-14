import torch
import torch.nn as nn
import pandas as pd

# -------------------------
# ETAPA 1: Dados de entrada
# -------------------------

def celsius_para_fahrenheit(celsius):
  return celsius * 1.8 + 32

# Dados manuais
temperaturas_celsius = [-10, 20, 100, 40, 70, 80]
temperaturas_fahrenheit = [celsius_para_fahrenheit(x) for x in temperaturas_celsius]

# Criando DataFrame
df = pd.DataFrame({
  'Celsius': temperaturas_celsius,
  'Fahrenheit': temperaturas_fahrenheit
})

# Convertendo dados para tensores
entrada = torch.FloatTensor(df.Celsius.values.astype(float)).view(-1, 1)
saida_esperada = torch.FloatTensor(df.Fahrenheit.values.astype(float)).view(-1, 1)

# -------------------------
# ETAPA 2: Definindo o modelo
# -------------------------

class Modelo(nn.Module):
  def __init__(self):
    super().__init__()
    self.camada_linear = nn.Linear(in_features=1, out_features=1, bias=True)

  def forward(self, x):
    return self.camada_linear(x)

# -------------------------
# ETAPA 3: Configuração do treinamento
# -------------------------

EPOCAS = 130
TAXA_APRENDIZADO = 1.2

modelo = Modelo()
criterio = nn.MSELoss() # O quao errado está ( LOSS )
otimizador = torch.optim.Adam(params=modelo.parameters(), lr=TAXA_APRENDIZADO) # pega o gradiente ( vetor de direçao ) e atualiza o os pesos de acordo

# -------------------------
# ETAPA 4: Treinamento
# -------------------------

pesos = []
biases = []

for epoca in range(EPOCAS):
  previsao = modelo(entrada)
  erro = criterio(previsao, saida_esperada)

  otimizador.zero_grad()
  erro.backward()
  otimizador.step()

  pesos.append(modelo.camada_linear.weight.item())
  biases.append(modelo.camada_linear.bias.item())

# -------------------------
# ETAPA 5: Resultado final
# -------------------------

print(f'Peso final: {modelo.camada_linear.weight.item():.2f}')
print(f'Bias final: {modelo.camada_linear.bias.item():.2f}')

# Salvando histórico de pesos e bias
historico = pd.DataFrame({'Peso': pesos, 'Bias': biases})
historico.to_csv('dados_treinamento.csv', index=False)

# -------------------------
# ETAPA 6: Teste de predição
# -------------------------

temperatura_teste = 120
entrada_teste = torch.FloatTensor([[temperatura_teste]])

saida_predita = modelo(entrada_teste).item()
saida_real = celsius_para_fahrenheit(temperatura_teste)

print(f'Predito pelo modelo: {saida_predita:.2f}°F')
print(f'Calculado matematicamente: {saida_real:.2f}°F')
