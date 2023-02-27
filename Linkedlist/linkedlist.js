class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor(head = null) {
    this.head = head;
  }
  error = null;

  get size() {
    let node = this.head;
    let i = 0;
    while (node) {
      i++;
      node = node.next;
    }
    return i;
  }

  append(data) {
    let newNode = new Node(data);
    let node = this.head;
    if (!node) {
      this.head = newNode;
      return;
    }
    while (node.next) {
      node = node.next;
    }
    node.next = newNode;
  }

  insertAtBegining(data) {
    let newNode = new Node(data);
    newNode.next = this.head;
    this.head = newNode;
  }

  reverseNode() {
    let prevNode = null;
    let currentNode = this.head;
    if (!currentNode) return;
    let nextNode;
    while (currentNode) {
      nextNode = currentNode.next;
      currentNode.next = prevNode;
      prevNode = currentNode;
      currentNode = nextNode;
    }
    this.head = prevNode;
  }

  insertAtIndex(index, data) {
    let newNode = new Node(data);
    let currentNode = this.head;
    if (index === 0) return this.insertAtBegining(data);
    if (index > this.size - 1) {
      console.log("Index out of range");
      return;
    }
    for (let i = 0; i < this.size; i++) {
      if (i + 1 === index) {
        let temp = currentNode.next;
        currentNode.next = newNode;
        newNode.next = temp;
        return;
      }
      currentNode = currentNode.next;
    }
  }

  deleteAtIndex(index) {
    let node = this.head;

    if (index > this.size - 1) {
      console.log("index out of range");
      return;
    }

    if (index === 0) this.head = this.head.next;

    for (let i = 0; i < index - 1; i++) node = node.next;
    node.next = node.next.next;
  }

  print() {
    let node = this.head;
    while (node) {
      console.log(node.data);
      node = node.next;
    }
  }
}

let list = new LinkedList();
list.append(5);
list.append(16);
list.append(12);
list.append(13);
list.append(14);
list.insertAtBegining(4);
list.insertAtIndex(2, 32);

list.deleteAtIndex(0);
list.insertAtIndex(0, 66);
list.print();
console.log(list.size);
