Adopted from [reading-list](https://github.com/blockstack/reading-list)

# Reading List for Decentralized Systems

A reading list of relevant research papers on blockchains, P2P networks, and storage systems

## <a name='TOC'>Table of Contents</a>

  1. [Blockchains](#blockchains)
  2. [Consensus](#consensus)
  3. [Consistency](#consistency)
  4. [Distributed Hash Tables](#dht)
  5. [Storage Systems](#storage)


## Why?
Cryptocurrency blockchains and decentralized systems built using them are marking a "second wave" of decentralized systems, where the first wave (2000-2005) was largely driven by advances in DHT and peer-to-peer systems. The problems that a lot of developers and researchers working on blockchain-based systems are trying to solve (like decentralized storage, decentralize DNS etc) were earlier investigated by a large number of researchers. It'd be unfortunate if the folks trying to build the new generation of such systems aren't aware of prior work and lessons learned.

## Contributions
Anyone can send pull requests to this repo and explain why a certain paper should be included. The reading-list is for systems that have been deployed in practice or lessons from real-world experiements e.g., from PlanetLab, and not for theoretically interesting papers. The list is currently maintained by [Muneeb Ali](http://twitter.com/muneeb) and others are welcome to help maintain the list. Paper additions might take a while since the maintainer(s) needs to go over the paper.

If you are reading this and taking the effort to understand these papers, you should consider joining the public Slack of [Blockstack](http://blockstack.org).

## <a name='blockchains'> Blockchains
* [Bitcoin-NG: A Scalable Blockchain Protocol](https://www.usenix.org/system/files/conference/nsdi16/nsdi16-paper-eyal.pdf) (2016): Bitcoin-NG (Next Generation) focuses on scalability. It's a Byzantine fault tolerant blockchain protocol that is
robust to extreme churn and shares the same trust model as Bitcoin. The paper also introduces quantitative metrics for evaluating Nakamoto consensus protocols.

* [Blockstack: A Global Naming and Storage System Secured by Blockchains](https://blockstack.org/blockstack.pdf) (2016): This paper presents the design and implementation of Blockstack, a global naming and storage system built on top of a blockchain. Blockstack is agnostic of the underlying blockchain, and currently uses Bitcoin. The paper also describes lessons from a production deployment of an earlier system that was on a smaller blockchain.

## <a name='consensus'> Consensus
* [In Search of an Understandable Consensus Algorithm](https://www.usenix.org/system/files/conference/atc14/atc14-paper-ongaro.pdf) (2014): This paper presents Raft, which is equivalent to multi-Paxos but much easier to understand. There have been dozens of real-world Raft implementations, some of which are in production use, within the couple of years that this work came out.

## <a name='consistency'> Consistency
* [Don’t Settle for Eventual: Scalable Causal Consistency for Wide-Area Storage with COPS](http://www-bcf.usc.edu/~wyattllo/papers/cops-sosp11.pdf) (2011): This paper defines casual+ consistency and presents a key/value store that delivers this consistency model across wide-area networks. The paper is also interesting to get background on different consistency models.

## <a name='dht'> Distributed Hash Tables
* [Experiences with CoralCDN: A Five-Year Operational View](http://www.cs.princeton.edu/~mfreed/docs/coral-nsdi10.pdf) (2010): CoralCDN provides an open (and free!) web content distributuion network (CDN) that anyone can use simply by appending .nyud.net to any URL. This paper presents lessons from a 5-year deployment of CoralCDN, one of the largest/longest real-world deployments of a DHT-based system. Paper presents challenges they faced and solutions that worked, along with lessons for building open systems.
* [Beehive: O(1) Lookup Performance for Power-Law Query Distributions in Peer-to-Peer Overlays](https://www.cs.cornell.edu/people/egs/papers/beehive.pdf) (2004): Beehive encourages looking at usage/query patterns of your target application and then optimizing caching in the DHT accordingly. DNS lookups (their target application) for example have a power-law query distribution and proactive replication can help a lot for performance in that case.

## <a name='storage'> Storage Systems
* [Separating key management from file system security](https://pdos.csail.mit.edu/papers/sfs:sosp99.pdf) (1999): This paper presents SFS (secure file system) that uses self-certifying names. SFS is motivated to have a global file system where key-management is handled outside of the file system. Self-certifying names, presented in an [earlier paper](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.43.8989&rep=rep1&type=pdf), are a key contribution and they're used by modern storage systems like [IPFS](http://ipfs.io). 
* [Efficient Replica Maintenance for Distributed Storage Systems](http://oceanstore.cs.berkeley.edu/publications/papers/pdf/carbonite06.pdf) (2006): This paper looks at replication strategies for distributed storage systems and tradeoff between false positives and rereplication costs, particularly in trying to accurately differentiate between nodes which have temporarily lost connectivity and those which are more permanently offline.
* [Dynamo: Amazon’s Highly Available Key-value Store](http://www.allthingsdistributed.com/files/amazon-dynamo-sosp2007.pdf) (2007): Dynamo is Amazon's production key/value store that makes a tradeoff between consistency for availability and performance and uses eventual consistency. Amazon actually controls all nodes where DynamoDB is deployed, trying to build a similar system under decentralization requirements is much harder.
* [Wide-area cooperative storage with CFS](https://pdos.csail.mit.edu/papers/cfs:sosp01/cfs_sosp.pdf) (2001): CFS is a P2P read-only storage system that uses Chord for DHT-routing and SFS for storage. CFS introduces a per-IP quota for limiting amount of data written by a single attacker.
* [Tahoe – The Least-Authority Filesystem](https://eprint.iacr.org/2012/524.pdf) (2008): Tahoe-LAFS is an [open-source](https://tahoe-lafs.org/trac/tahoe-lafs) file store that takes many ideas from theory, like principle of least authority and Reed-Solomon codes etc., to build a practical storage system that is commercially used. 