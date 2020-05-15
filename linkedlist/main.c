#include "queue.h"
#include "type.h"

int main(){
    // print_function = print_type;
    // Queue queue = new_queue_with_type(getType());
    
    // push(queue, new_item( new_type(1) ));
    // push(queue, new_item( new_type(2) ));
    // push(queue, new_item( new_type(3) ));
    // push(queue, new_item( new_type(4) ));
    
    // print(queue);

    Queue queue = new_queue_string();
    push(queue, new_item("Ciao"));
    push(queue, new_item("come"));
    push(queue, new_item("va"));
    push(queue, new_item("?"));
    print(queue);


    Queue queue2 = new_queue();
    push(queue2, new_item("Ciao"));
    push(queue2, new_item("come"));
    push(queue2, new_item("va"));
    push(queue2, new_item("?"));
    print(queue2);


    pop(queue);
    Item i = pop(queue2);
    delete_Queue(queue);


    printf("\n\nInformazione = %s\n\n\n", get_info(i));
    print(queue2);

    delete_Queue(queue2);   


    return 0;
}