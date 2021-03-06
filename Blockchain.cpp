using namespace std;

class Blockchain    
{
    //Section 1 Genesis block creation
    constructor()
    {
        this.chain = [this.createGenesisBlock()];
    }
    createGenesisBlock()
    {
        return new Block(0, "11/15/2018", "Genesis block", "0");
    }
    
    //section 2 adding new blocks
    getLatestBlock()
    {
        return this.chain[this.chain.length - 1];
    }
    addBlock(newBlock) {
        newBlock.previousHas = this.getLatestBlock().hash;
        newBlock.hash = newBlock.calculateHash();
        this.chain.push(newBlock);
    }
    
    //section 3 vaidating the chain
    isChainValid()
    {
        for (let i = 1; i < this.chain.length; i++)
        {
            const currentBlock = this.chain[i];
            const previousBlock = this.chain[i - 1];
            
            if (currentBlock.hash !== currentBlock.calculateHash())
            {
                return false;
            }
            if (currentBlock.previousHash !== previousBlock.hash)
            {
                return false;
            }
            return true;
        }
    }
    let BlockGeeksCoin = new Blockchain();
    
    BlockGeeksCoin.addBlock(new Block(1, "11/15/2018", { amount: 4 })); 
    BlockGeeksCoin.addBlock(new Block(2, "11/15/2019", { amount: 8 }));
}
