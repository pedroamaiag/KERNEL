# Kernel EDF - Monitoramento ISS

Este projeto implementa um **Sistema Operacional de Tempo Real (RTOS)** simplificado para Arduino Mega, utilizando o algoritmo de escalonamento **EDF (Earliest Deadline First)**. O sistema é integrado a uma interface Python que monitora a posição da Estação Espacial Internacional (ISS) e envia sinais via Serial para acionamento de alertas visuais no hardware.

## Estrutura do Software

O sistema foi desenvolvido seguindo uma arquitetura modular para garantir independência entre hardware e lógica de aplicação:

* **Camada de Escalonamento (Kernel):** Gerencia a fila de processos e decide qual tarefa deve ser executada com base no menor prazo de finalização (*deadline*).
* **Camada de Abstração (Drivers):** Central de controle que padroniza a comunicação com os periféricos (LED e UART).
* **Aplicação:** Tarefas periódicas que monitoram a porta serial e gerenciam o comportamento dos alertas.
* **Interface Externa:** Script Python que consome APIs geográficas e atua como o sensor de posição da ISS.

## Organização dos Arquivos

### Núcleo do S.O.
* `kernel.cpp` / `kernel.h`: Lógica do escalonador e gerenciamento de processos.
* `ctr_drv.cpp` / `ctr_drv.h`: Gerenciador central de drivers.
* `dd_types.h`: Definições de constantes, IDs de drivers e comandos.

### Drivers de Hardware
* `drv_uart.cpp` / `drv_uart.h`: Comunicação serial com tratamento de erros e limpeza de buffer.
* `drv_led.cpp` / `drv_led.h`: Controle de GPIO via registradores do ATmega2560.

### Lógica de Controle
* `sketch.ino`: Configuração de hardware (Timers), inicialização do Kernel e definição das tarefas de monitoramento.
* `interface.py` / `main.py`: Interface gráfica em Tkinter e lógica de requisição de dados da ISS.

---

## Simulação no Wokwi

Para reproduzir o hardware deste projeto no simulador **Wokwi**, crie um arquivo chamado `diagram.json` e utilize a configuração abaixo:

```json
{
  "version": 1,
  "author": "User",
  "editor": "wokwi",
  "parts": [
    { "type": "wokwi-arduino-mega", "id": "mega", "top": 0, "left": 0 },
    { "type": "wokwi-led", "id": "led1", "top": -100, "left": 150, "attrs": { "color": "red" } }
  ],
  "connections": [
    [ "mega:22", "led1:A", "red", [ "v0" ] ],
    [ "mega:GND.2", "led1:C", "black", [ "v0" ] ]
  ],
  "serialPorts": [
    { "type": "wokwi-serial-port", "id": "serial0", "port": 0 }
  ]
}
