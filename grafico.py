import matplotlib.pyplot as plt
import numpy as np

def main():
    tamanhosDados = [100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
    tempoHeap = [0.000007, 0.000083, 0.000820, 0.010858, 0.116310, 1.361972, 17.185452]
    tempoMerge = [0.000007, 0.000069, 0.000894, 0.009561, 0.104502, 1.228246, 14.958486]
    tempoQuick = [0.000004, 0.000040, 0.000500, 0.006049, 0.069103, 0.933233, 11.575221]
    tempoInsert = [0.000005, 0.000035, 0.000817, 0.029811, 1.131172, 53.775981, 2755.158692]

    tempoHeapOp = [0.000009, 0.000085, 0.000825, 0.010172, 0.124272, 1.391351, 12.847845]
    tempoMergeOp = [0.000008, 0.000059, 0.000729, 0.006913, 0.087685, 0.911376, 8.228395]
    tempoQuickOp = [0.000005, 0.000046, 0.000918, 0.024143, 0.852423, 23.399059, 764.985492]
    tempoInsertOp = [0.000004, 0.000024, 0.000363, 0.003138, 0.040389, 0.326847, 3.189158]

    plt.figure(figsize=(20, 10))
    plt.plot(tamanhosDados, tempoHeap, marker='o', color='b', label='Com Heap')
    plt.plot(tamanhosDados, tempoMerge, marker='o', color='g', label='Com Merge')
    plt.plot(tamanhosDados, tempoQuick, marker='o', color='y', label='Com Quick')
    plt.plot(tamanhosDados, tempoInsert, marker='o', color='r', label='Com Insert')
    plt.xscale('log')
    plt.yscale('log')
    plt.xlabel('Tamanho de Dados (potências de 10)')
    plt.ylabel('Tempo para Ordenação (potências de 10)')
    plt.title('Gráfico de Tempo para Ordenação vs Tamanho de Dados')
    plt.legend()
    plt.grid(True, which="both", linestyle='-', linewidth=1)

    # Tenta salvar a imagem
    try:
        plt.savefig('/home/talescruz/Área de Trabalho/grafico_tempo_ordenacao.png')
        print("Gráfico salvo com sucesso como 'grafico_tempo_ordenacao.png'")
    except Exception as e:
        print("Erro ao salvar o gráfico:", e)
        plt.show()  # Exibe o gráfico caso não consiga salvar



    plt.figure(figsize=(20, 10))
    plt.plot(tamanhosDados, tempoHeap, marker='o', color='b', label='Com Heap')
    plt.plot(tamanhosDados, tempoMerge, marker='o', color='g', label='Com Merge')
    plt.plot(tamanhosDados, tempoQuick, marker='o', color='y', label='Com Quick')
    plt.plot(tamanhosDados, tempoInsert, marker='o', color='r', label='Com Insert')
    plt.xscale('log')
    plt.yscale('log')
    plt.xlabel('Tamanho de Dados (potências de 10)')
    plt.ylabel('Tempo para Ordenação (potências de 10)')
    plt.title('Gráfico de Tempo para Ordenação vs Tamanho de Dados')
    plt.legend()
    plt.grid(True, which="both", linestyle='-', linewidth=1)

    # Tenta salvar a imagem
    try:
        plt.savefig('/home/talescruz/Área de Trabalho/grafico_tempo_ordenacao_po.png')
        print("Gráfico salvo com sucesso como 'grafico_tempo_ordenacao_po.png'")
    except Exception as e:
        print("Erro ao salvar o gráfico:", e)
        plt.show()  # Exibe o gráfico caso não consiga salvar


if __name__ == "__main__":
    main()