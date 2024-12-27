class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class LinkedList {
    constructor(value) {
        const newNode = new Node(value);
        this.head = newNode;
        this.tail = newNode;
        this.length = 1;
    }

    push(value) {
        const newNode = new Node(value);
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
        }
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++;
        return this

    }

    pop() {
        if (!this.head) return undefined;
        if (this.length === 1) {
            let temp = this.head;
            this.head = null;
            this.tail = null;
            this.length--;
            return temp;
        }
        let temp = this.head;
        let pre = this.head;
        while (temp.next) {
            pre = temp;
            temp = temp.next;
        }
        this.tail = pre;
        this.tail.next = null;
        this.length--;

        return temp;
    }

    unshift(value) {
        const newNode = new Node(value)
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
        }
        let firstNode = this.head;
        newNode.next = firstNode;
        this.head = newNode;
        this.length++;
        return this;
    }

    shift() {
        if (!this.head) return undefined

        if (this.length === 1) {
            this.head = null;
            this.tail = null;
            this.length--;
            return
        }
        let temp = this.head;
        this.head = this.head.next;
        temp.next = null;
        this.length--;
        return temp;
    }


    get(index) {
        if (index < 0 || index >= this.length) {
            return undefined;
        }
        let temp = this.head
        for (let i = 0; i < index; i++) {
            temp = temp.next
        }
        return temp
    }

    set(index, value) {
        let temp = this.get(index)
        if (temp) {
            temp.value = value;
            return true;
        }
        return false;
    }

    insert(index, value) {
        if (index > this.length || index < 0) return false;
        if (index === 0) {
            let temp = this.unshift(value);
            return true
        }
        if (index === this.length) {
            let temp = this.push(value);
            return true
        }
        const newNode = new Node(value)
        let temp = this.get(index - 1);
        newNode.next = temp.next;
        temp.next = newNode;
        this.length++;
        return true
    }

    remove(index){
        if(index >= this.length || index < 0) return false
        if(index === this.length -1) return this.pop();
        if(index === 0) return this.shift();
        const pre = this.get(index - 1);
        const temp = pre.next
        pre.next = temp.next;
        temp.next = null
        this.length--;
        return true;
    }

    reverse(){
        let temp = this.head;
        this.head = this.tail
        this.tail = temp
        let next = temp.next;
        let prev = null;
        for (let i = 0; i < this.length; i++){
            next = temp.next;
            temp.next = prev;
            prev = temp;
            temp = next;
        }
        return this;
    }
}