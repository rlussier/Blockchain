const SHA256 = require("cryto-js/sha256");

class Block
{
    constructor(index, timestamp, data, previousHas = '')
    {
        this.index = index;
        this.previousHash = previousHash;
        this.temstamp = timestamp;
        this.data = data;
        this.hash = this.calculateHash();
    }
    
    calculateHash()
    {
        return SHA256(this.index + this.previousHash + this.timestamp + JSON.stringify(this.data)).toString();
    }
}
