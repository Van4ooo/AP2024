#include "sorts_list.h"

const long long unsigned Leonardo_k[] = {
    1, 1, 3, 5, 9, 15, 25, 41, 67, 109, 177, 287, 465, 753, 1219,
    1973, 3193, 5167, 8361, 13529, 21891, 35421u, 57313u, 92735u,
    150049u, 242785u, 392835u, 635621u, 1028457u, 1664079u, 2692537u,
    4356617u, 7049155u, 11405773u, 18454929u, 29860703u, 48315633u,
    78176337u, 126491971u, 204668309u, 331160281u, 535828591u, 866988873u,
    1402817465u, 2269806339u, 3672623805u, 5942430145u, 9615053951u,
    15557484097u, 25172538049u, 40730022147u, 65902560197u, 106632582345u,
    172535142543u, 279167724889u, 451702867433u, 730870592323u,
    1182573459757u, 1913444052081u, 3096017511839u, 5009461563921u,
    8105479075761u, 13114940639683u, 21220419715445u, 34335360355129u,
    55555780070575u, 89891140425705u, 145446920496281u, 235338060921987u,
    380784981418269u, 616123042340257u, 996908023758527u, 1613031066098785u,
    2609939089857313u, 4222970155956099u, 6832909245813413u,
    11055879401769513u, 17888788647582927u, 28944668049352441u,
    46833456696935369u, 75778124746287811u, 122611581443223181u,
    198389706189510993u, 321001287632734175u, 519390993822245169u,
    840392281454979345u, 1359783275277224515u, 2200175556732203861u,
    3559958832009428377u, 5760134388741632239u, 9320093220751060617u,
    15080227609492692857u
};


void sorts::SmoothSort::init_leonardo_heap(int *array, size_t _N){
    data = array;
    N = _N;

    tree_vector = 3;
    first_tree = 0;

    if(N > 1 && get(data, 0) > get(data, 1))
     swap(&data[0], &data[1]);

    for(size_t i=2; i<N; i++)
        insertion_sort(i);
}

void sorts::SmoothSort::insertion_sort(size_t element){
    if((tree_vector & 1) && (tree_vector & 2)) {
        tree_vector = (tree_vector >> 2) | 1;
        first_tree += 2;
    } else if(first_tree == 1) {
        tree_vector = (tree_vector << 1) | 1;
        first_tree = 0;
    } else {
        tree_vector = (tree_vector << (first_tree-1)) | 1;
        first_tree = 1;
    }

    filter(element, first_tree);
}

void sorts::SmoothSort::dequeue_max(size_t element){
    if(first_tree >= 2) {
        tree_vector = (tree_vector << 1) ^ 3;
        first_tree -= 2;

        filter(element-Leonardo_k[first_tree]-1, first_tree+1, false);
        tree_vector = (tree_vector << 1) | 1;
        filter(element-1, first_tree, false);
    } else if(first_tree == 0) {
        tree_vector >>= 1;
        first_tree = 1;
    } else {
        tree_vector >>=1;
        first_tree++;

        for(; first_tree<N+1; first_tree++, tree_vector>>=1)
            if(tree_vector & 1) break;
    }
}

void sorts::SmoothSort::heapify(size_t root, size_t order){
    size_t comp, comp_order;

    while(true) {
        if(order <= 1) break;

        if(get(data, root-1) > get(data, root-1-Leonardo_k[order-2])) {
            comp = root-1;
            comp_order = order-2;
        } else {
            comp = root-1-Leonardo_k[order-2];
            comp_order = order-1;
        }

        if(get(data, comp) > get(data, root))
            swap(&data[root], &data[comp]);
        else
            break;

        root = comp;
        order = comp_order;
    }
}

void sorts::SmoothSort::filter(size_t element, size_t order, bool test_children){
    size_t current = element;
    size_t order_current = order;
    size_t size_current;
    size_t bitvector_mask = 2;

    while(true) {
        size_current = Leonardo_k[order_current];
        if(size_current > current) break;

        if(!(get(data, current-size_current) > get(data, current))) {
            break;
        } else if((size_current == 1) || !test_children) {
            swap(&data[current], &data[current-size_current]);
        } else {
            if((get(data, current-size_current) > get(data, current-1))
                && (get(data, current-size_current) > get(data, current-1-Leonardo_k[order_current-2])))
                swap(&data[current], &data[current-size_current]);
            else break;
        }

        order_current++;
        for(; order_current<N+1; order_current++, bitvector_mask<<=1) {
            if(tree_vector & bitvector_mask) {
                bitvector_mask <<= 1;
                break;
            }
        }
        current -= size_current;
    }
    heapify(current, order_current);
}


void sorts::SmoothSort::cpp_run(int* data, size_t N) {
    init_leonardo_heap(data, N);

    for(size_t i=1; i<N-1; i++)
        dequeue_max(N-i);

    memory_req += sizeof(Leonardo_k);
}
