class Block{
    #transaction;
    #blockHash;
    #previousHash;
    static number;
    constructor(previousHash = 0, transaction){
        

        let contents = [previousHash,btoa(transaction)];
        this.#previousHash = previousHash;
        
        this.#transaction = transaction;
        
        this.#blockHash = btoa(contents);
        ++number;
        
        console.log(number + " previous Hash = " + this.#previousHash);
        console.log(number + " transaction = " + this.#transaction);
        console.log(number + " hashed Transaction = " + btoa(transaction));
        console.log(number + " contents = " + contents);
        console.log(number + " block hash = " + this.#blockHash);
    }

    setTransaction(transaction){
        this.#transaction = transaction; 
    }
    getTransaction(){
        return this.#transaction;
    }
    setPreviousHash(previousHash){
        this.#previousHash = previousHash;
    }
    getPrevioushash(){
        return this.#previousHash;
    }
    setBlockHash(blockHash){
        this.#blockHash = blockHash;
    }
    getBlockHash(){
        return this.#blockHash;
    }
}
number = 0;

let genesisTransaction = ["Numaan sent Mujib a link"];
let genesisBlock = new Block(0,genesisTransaction);

let transaction = ["Mujib sent Ahsan a link"];
let nextblock = new Block(genesisBlock.getBlockHash(), transaction);

document.write("Hello");