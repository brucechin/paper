
# Awesome System for Machine Learning 

Adopted from (Awesome System for ML)[https://github.com/HuaizhengZhang/Awesome-System-for-Machine-Learning] and (SysML-reading-list)[https://github.com/mcanini/SysML-reading-list]


## General Resources
- [Survey](#survey)
- [Book](#book)
- [Video](#video)
- [Course](#course)
- [Blog](#blog)
- [Tool](#userful-tools)
- [Project with code](#project)

## System for AI Papers
- [Data Processing](data_processing.md#data-processing)
- [Training System](training.md#training-system)
- [Inference System](inference.md#inference-system)
- [Machine Learning Infrastructure](infra.md#machine-learning-infrastructure)
- [AutoML System](AutoML_system.md#automl-system)
- [Deep Reinforcement Learning System](drl_system.md#deep-reinforcement-learning-system)
- [Edge AI](edge_system.md#edge-or-mobile-papers)
- [Video System](video_system.md#video-system)



## Review

A Berkeley View of Systems Challenges for AI
https://arxiv.org/pdf/1712.05855.pdf

Strategies and Principles of Distributed Machine Learning on Big Data
https://arxiv.org/abs/1512.09295

## Background

Deep learning
Nature volume 521, 2015
https://www.nature.com/articles/nature14539

Deep learning reading list
http://deeplearning.net/reading-list

## Measurement

Multi-tenant GPU Clusters for Deep LearningWorkloads: Analysis and Implications
https://www.microsoft.com/en-us/research/uploads/prod/2018/05/gpu_sched_tr.pdf

## Frameworks

TensorFlow: A System for Large-Scale Machine Learning
OSDI 2016
https://www.usenix.org/system/files/conference/osdi16/osdi16-abadi.pdf

Ray: A Distributed Framework for Emerging AI Applications
OSDI 2018
https://www.usenix.org/system/files/osdi18-moritz.pdf

## Tuning

HyperDrive: Exploring Hyperparameters with POP Scheduling
MiddleWare 2017
https://dl.acm.org/citation.cfm?id=3135994

Ease.ml: Towards Multi-tenant Resource Sharing for Machine Learning Workloads
VLDB 2018
http://www.vldb.org/pvldb/vol11/p607-li.pdf

Automating Model Search for Large Scale Machine Learning
SoCC 2015
http://dl.acm.org/authorize?N91362

Google Vizier: A Service for Black-Box Optimization
KDD 2017
https://dl.acm.org/citation.cfm?id=3098043

Hyperband: A Novel Bandit-Based Approach to Hyperparameter Optimization
Journal of Machine Learning Research 18 (2018)
https://arxiv.org/pdf/1603.06560.pdf

Hyperopt: a Python library for model selection and hyperparameter optimization
Computational Science & Discovery, 8(1) 2015 
http://iopscience.iop.org/article/10.1088/1749-4699/8/1/014008

Auto-Keras: Efficient Neural Architecture Search with Network Morphism
https://arxiv.org/pdf/1806.10282v2.pdf

## Runtime execution

Cavs: An Efficient Runtime System for Dynamic Neural Networks
ATC 2018
https://www.usenix.org/system/files/conference/atc18/atc18-xu-shizhen.pdf

TVM: An Automated End-to-End Optimizing Compiler for Deep Learning
OSDI 2018
https://www.usenix.org/system/files/osdi18-chen.pdf

PipeDream: Fast and Efficient Pipeline Parallel DNN Training
https://arxiv.org/pdf/1806.03377.pdf

STRADS: A Distributed Framework for Scheduled Model Parallel Machine Learning
EuroSys 2016
https://dl.acm.org/citation.cfm?id=2901331

Dynamic Control Flow in Large-Scale Machine Learning
EuroSys 2018
https://dl.acm.org/citation.cfm?id=3190551

Improving the Expressiveness of Deep Learning Frameworks with Recursion
EuroSys 2018
https://dl.acm.org/citation.cfm?id=3190530

Continuum: A Platform for Cost-Aware, Low-Latency Continual Learning
SoCC 2018
https://dl.acm.org/citation.cfm?id=3267817

KeystoneML: Optimizing Pipelines for Large-ScaleAdvanced Analytics
ICDE 2017
https://amplab.cs.berkeley.edu/wp-content/uploads/2017/01/ICDE_2017_CameraReady_475.pdf

Owl: A General-Purpose Numerical Library in OCaml
https://arxiv.org/pdf/1707.09616.pdf

## Distributed learning

Large Scale Distributed Deep Networks
NIPS 2012
https://ai.google/research/pubs/pub40565.pdf

Managed Communication and Consistency for Fast Data-Parallel Iterative Analytics
SoCC 2015
http://dl.acm.org/authorize?N91363

Ako: Decentralised Deep Learning with Partial Gradient Exchange
SOCC 2016
https://lsds.doc.ic.ac.uk/sites/default/files/ako-socc16.pdf

Poseidon: An Efficient Communication Architecture for Distributed Deep Learning on GPU Clusters
ATC 2017
https://www.usenix.org/system/files/conference/atc17/atc17-zhang.pdf

Parameter Hub: a Rack-Scale Parameter Server for Distributed Deep Neural Network Training
SoCC 2018
https://dl.acm.org/citation.cfm?id=3267840

MXNet: A Flexible and Efficient Machine Learning Library for Heterogeneous Distributed Systems
ML Systems Workshop at NIPS 2016
https://arxiv.org/pdf/1512.01274.pdf

Scaling Distributed Machine Learning with the Parameter Server
OSDI 2014
https://www.usenix.org/system/files/conference/osdi14/osdi14-paper-li_mu.pdf

Project Adam: Building an Efficient and Scalable Deep Learning Training System
OSDI 2014
https://www.usenix.org/system/files/conference/osdi14/osdi14-paper-chilimbi.pdf

Orpheus: Efficient Distributed Machine Learning via System and Algorithm Co-design
SoCC 2018
https://dl.acm.org/citation.cfm?id=3267810

Petuum: A New Platform for Distributed Machine Learning on Big Data
KDD 2015
https://arxiv.org/pdf/1312.7651.pdf

GPipe: Efficient Training of Giant Neural Networks using Pipeline Parallelism
https://arxiv.org/pdf/1811.06965.pdf

## Serving systems and inference

DeepCPU: Serving RNN-based Deep Learning Models 10x Faster
ATC 2018
https://www.usenix.org/system/files/conference/atc18/atc18-zhang-minjia.pdf

Clipper: A Low-Latency Online Prediction Serving System
NSDI 2017
https://www.usenix.org/system/files/conference/nsdi17/nsdi17-crankshaw.pdf

Research for Practice: Prediction-Serving Systems
ACM Queue 16(1), 2018
https://queue.acm.org/detail.cfm?id=3210557

InferLine: ML Inference Pipeline Composition
https://arxiv.org/pdf/1812.01776.pdf

PRETZEL: Opening the Black Box of Machine Learning Prediction Serving Systems
OSDI 2018
https://www.usenix.org/system/files/osdi18-lee.pdf

Olympian: Scheduling GPU Usage in a Deep Neural Network Model Serving System
MiddleWare 2018
https://dl.acm.org/citation.cfm?id=3274813

Low Latency RNN Inference with Cellular Batching
EuroSys 2018
https://dl.acm.org/citation.cfm?id=3190541

SERF: Efficient Scheduling for Fast Deep Neural Network Serving via Judicious Parallelism
SC 2016
https://ieeexplore.ieee.org/document/7877104

NoScope: Optimizing Neural Network Queries over Video at Scale
VLDB 2017
https://dl.acm.org/citation.cfm?id=3137664

Scheduling
Optimus: An Efficient Dynamic Resource Scheduler for Deep Learning Clusters
EuroSys 2018
https://dl.acm.org/citation.cfm?id=3190517

SLAQ: Quality-Driven Scheduling for Distributed Machine Learning
SoCC 2017
https://dl.acm.org/authorize?N46878

Proteus: agile ML elasticity through tiered reliability in dynamic resource markets 
EuroSys 2017
https://dl.acm.org/citation.cfm?id=3064182

Gandiva: Introspective Cluster Scheduling for Deep Learning
OSDI 2018
https://www.usenix.org/system/files/osdi18-xiao.pdf

Topology-Aware GPU Scheduling for Learning Workloads in Cloud Environments
SC 2017
https://dl.acm.org/citation.cfm?id=3126933

## Algorithmic aspects in scalable ML

Hemingway: Modeling Distributed Optimization Algorithms
ML Systems Workshop at NIPS 2016
https://arxiv.org/pdf/1702.05865.pdf

Asynchronous Methods for Deep Reinforcement Learning
ICML 2016
http://proceedings.mlr.press/v48/mniha16.pdf

Don't Use Large Mini-Batches, Use Local SGD
https://arxiv.org/pdf/1808.07217.pdf

GeePS: Scalable deep learning on distributed GPUs with a GPU-specialized parameter server
EuroSys 2016
https://dl.acm.org/citation.cfm?id=2901323

ImageNet Training in Minutes
ICPP 2018
https://dl.acm.org/citation.cfm?id=3225069

Semantics-Preserving Parallelization of Stochastic Gradient Descent
IPDPS 2018
https://ieeexplore.ieee.org/abstract/document/8425176

HOGWILD!: A Lock-Free Approach to ParallelizingStochastic Gradient Descent
NIPS 2011
https://papers.nips.cc/paper/4390-hogwild-a-lock-free-approach-to-parallelizing-stochastic-gradient-descent.pdf

QSGD: Communication-Efficient SGD via Randomized Quantization
NIPS 2017
https://papers.nips.cc/paper/6768-qsgd-communication-efficient-sgd-via-gradient-quantization-and-encoding.pdf

Can Decentralized Algorithms Outperform Centralized Algorithms? A Case Study for Decentralized Parallel Stochastic Gradient Descent
NIPS 2017
https://papers.nips.cc/paper/7117-can-decentralized-algorithms-outperform-centralized-algorithms-a-case-study-for-decentralized-parallel-stochastic-gradient-descent.pdf

Slow and Stale Gradients Can Win the Race: Error-Runtime Trade-offs in Distributed SGD
AIStats 2018
https://arxiv.org/pdf/1803.01113.pdf

Probabilistic Synchronous Parallel
https://arxiv.org/pdf/1709.07772.pdf

## AI Testing and Verification

DeepXplore: Automated Whitebox Testing of Deep Learning Systems
SOSP 2017
https://dl.acm.org/authorize?N47145

Programmatically Interpretable Reinforcement Learning
ICML 2018
https://arxiv.org/pdf/1804.02477.pdf

AI2: Safety and Robustness Certification of Neural Networks with Abstract Interpretation
SP 2018
https://ieeexplore.ieee.org/document/8418593

## Interpretability and Explainability

“Why Should I Trust You?”Explaining the Predictions of Any Classifier
KDD 2016
https://www.kdd.org/kdd2016/papers/files/rfp0573-ribeiroA.pdf

Learning to Explain: An Information-Theoretic Perspective on Model Interpretation
ICML 2018
https://arxiv.org/pdf/1802.07814.pdf

A Unified Approach to Interpreting Model Predictions
NIPS 2017
https://papers.nips.cc/paper/7062-a-unified-approach-to-interpreting-model-predictions.pdf

The Mythos of Model Interpretability
WHI 2016
https://arxiv.org/pdf/1606.03490.pdf

## Model Management

MISTIQUE: A System to Store and Query Model Intermediates for Model Diagnosis
SIGMOD 2018
https://dl.acm.org/citation.cfm?id=3196934

MODELDB: A System for Machine Learning Model Management
HILDA 2016
https://mitdbg.github.io/modeldb/papers/hilda_modeldb.pdf

Model Governance: Reducing the Anarchy of Production ML
ATC 2018
https://www.usenix.org/system/files/conference/atc18/atc18-sridhar.pdf

The Missing Piece in Complex Analytics: Low Latency,Scalable Model Management and Serving with Velox
CIDR 2015
http://www.bailis.org/papers/velox-cidr2015.pdf

Bandana: Using Non-volatile Memory for Storing Deep Learning Models
SysML 2019
https://arxiv.org/abs/1811.05922

## Hardware

Deep learning with limited numerical precision
ICML 2015
http://proceedings.mlr.press/v37/gupta15.pdf

In-Datacenter Performance Analysis of a Tensor Processing Unit
ISCA 2017
https://dl.acm.org/citation.cfm?id=3080246

Serving DNNs in Real Timeat Datacenter Scale with Project Brainwave
IEEE MICRO 38(2), Mar./Apr. 2018
https://ieeexplore.ieee.org/document/8344479

## Security aspects

Efficient Deep Learning on Multi-Source Private Data
https://arxiv.org/pdf/1807.06689.pdf

Chiron: Privacy-preserving Machine Learning as a Service
https://arxiv.org/pdf/1803.05961.pdf

MLCapsule: Guarded Offline Deployment of Machine Learning as a Service
https://arxiv.org/pdf/1808.00590.pdf

Slalom: Fast, Verifiable and Private Execution of Neural Networks in Trusted Hardware
https://arxiv.org/pdf/1806.03287.pdf

Privado: Practical and Secure DNN Inference
https://arxiv.org/pdf/1810.00602.pdf

## ML Platforms (Applied)

Applied Machine Learning at Facebook: A Datacenter Infrastructure Perspective
HPCA 2018
https://research.fb.com/publications/applied-machine-learning-at-facebook-a-datacenter-infrastructure-perspective/

Machine Learning at Facebook: Understanding Inference at the Edge
HPCA 2019
https://research.fb.com/publications/machine-learning-at-facebook-understanding-inference-at-the-edge/

Meet Michelangelo: Uber’s Machine Learning Platform
https://eng.uber.com/michelangelo/

Introducing FBLearner Flow: Facebook’s AI backbone
https://code.fb.com/core-data/introducing-fblearner-flow-facebook-s-ai-backbone/

TFX: A TensorFlow-Based Production-Scale Machine LearningPlatform
http://dl.acm.org/authorize?N33328

Horovod: fast and easy distributed deep learning in TensorFlow
https://arxiv.org/pdf/1802.05799v3.pdf

## ML for Systems

Resource Central: Understanding and Predicting Workloads for Improved Resource Management in Large Cloud Platforms
SOSP 2017
https://dl.acm.org/authorize?N47144

Adaptive Execution of Continuous and Data-intensive Workflows with Machine Learning
MiddleWare 2018
https://dl.acm.org/citation.cfm?id=3274827

AuTO: Scaling Deep Reinforcement Learning to Enable Datacenter-Scale Automatic Traffic Optimization
SIGCOMM 2018
https://dl.acm.org/citation.cfm?id=3230551

Neural Adaptive Video Streaming with Pensieve
SIGCOMM 2017
https://dl.acm.org/citation.cfm?id=3098843

Neural Adaptive Content-aware Internet Video Delivery
OSDI 2018
https://www.usenix.org/system/files/osdi18-yeo.pdf

## Workshops

Systems for ML and Open Source Software Workshop at NeurIPS 2018
http://learningsys.org/nips18/acceptedpapers.html

SysML 2018
http://www.sysml.cc/2018/index.html

Engineering Dependable and Secure Machine Learning Systems 2019
https://sites.google.com/view/edsmls2019/program

Engineering Dependable and Secure Machine Learning Systems 2018
https://sites.google.com/edu.haifa.ac.il/edsmls/program

Workshop on Distributed Machine Learning 2017
https://distributedml2017.wordpress.com/schedule/

ML Systems Workshop at NIPS 2016
https://sites.google.com/site/mlsysnips2016/accepted-papers

## Upcoming 2019

ColumnML: Column Store Machine Learning with On The Fly Data Transformation
VLDB 2019

Continuous Integration of Machine Learning Models: A Rigorous Yet Practical Treatment
SysML 2019

Seer: Leveraging Big Data to Navigate the Complexity of Performance Debugging in Cloud Microservices
ASPLOS 2019

RLgraph: Flexible Computation Graphs for Deep Reinforcement Learning
SysML 2019
https://arxiv.org/pdf/1810.09028.pdf



## Survey
- Toward Highly Available, Intelligent Cloud and ML Systems [[Slide]](http://sysnetome.com/Talks/cguo_netai_2018.pdf)
- awesome-production-machine-learning: A curated list of awesome open source libraries to deploy, monitor, version and scale your machine learning [[GitHub]](https://github.com/EthicalML/awesome-production-machine-learning)
- Opportunities and Challenges Of Machine Learning Accelerators In Production [[Paper]](https://www.usenix.org/system/files/opml19papers-ananthanarayanan.pdf)
  - Ananthanarayanan, Rajagopal, et al. "
  - 2019 {USENIX} Conference on Operational Machine Learning (OpML 19). 2019.
- How (and How Not) to Write a Good Systems Paper [[Advice]](https://www.usenix.org/legacy/events/samples/submit/advice_old.html)
- Applied machine learning at Facebook: a datacenter infrastructure perspective [[Paper]](https://research.fb.com/wp-content/uploads/2017/12/hpca-2018-facebook.pdf)
  - Hazelwood, Kim, et al. (*HPCA 2018*)
- Infrastructure for Usable Machine Learning: The Stanford DAWN Project
  - Bailis, Peter, Kunle Olukotun, Christopher Ré, and Matei Zaharia. (*preprint 2017*)
- Hidden technical debt in machine learning systems [[Paper]](https://papers.nips.cc/paper/5656-hidden-technical-debt-in-machine-learning-systems.pdf)
  - Sculley, David, et al. (*NIPS 2015*)
- End-to-end arguments in system design [[Paper]](http://web.mit.edu/Saltzer/www/publications/endtoend/endtoend.pdf)
  - Saltzer, Jerome H., David P. Reed, and David D. Clark. 
- System Design for Large Scale Machine Learning [[Thesis]](http://shivaram.org/publications/shivaram-dissertation.pdf)
- Deep Learning Inference in Facebook Data Centers: Characterization, Performance Optimizations and Hardware Implications [[Paper]](https://arxiv.org/pdf/1811.09886.pdf)
  - Park, Jongsoo, Maxim Naumov, Protonu Basu et al. *arXiv 2018*
  - Summary: This paper presents a characterizations of DL models and then shows the new design principle of DL hardware.
- A Berkeley View of Systems Challenges for AI [[Paper]](https://arxiv.org/pdf/1712.05855.pdf)


## Book

- Computer Architecture: A Quantitative Approach [[Must read]](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.115.1881&rep=rep1&type=pdf)
- Streaming Systems [[Book]](https://www.oreilly.com/library/view/streaming-systems/9781491983867/)
- Kubernetes in Action (start to read) [[Book]](https://www.oreilly.com/library/view/kubernetes-in-action/9781617293726/)
- Machine Learning Systems: Designs that scale [[Website]](https://www.manning.com/books/machine-learning-systems)

## Video

- ScalaDML2020: Learn from the best minds in the machine learning community. [[Video]](https://info.matroid.com/scaledml-media-archive-preview)
- From Research to Production with PyTorch [[Video]](https://www.infoq.com/presentations/pytorch-torchscript-botorch/#downloadPdf/)
- Introduction to Microservices, Docker, and Kubernetes [[YouTube]](https://www.youtube.com/watch?v=1xo-0gCVhTU)
- ICML Keynote: Lessons Learned from Helping 200,000 non-ML experts use ML [[Video]](https://slideslive.com/38916584/keynote-lessons-learned-from-helping-200000-nonml-experts-use-ml)
- Adaptive & Multitask Learning Systems [[Website]](https://www.amtl-workshop.org/schedule)
- System thinking. A TED talk. [[YouTube]](https://www.youtube.com/watch?v=_vS_b7cJn2A)
- Flexible systems are the next frontier of machine learning. Jeff Dean [[YouTube]](https://www.youtube.com/watch?v=Jnunp-EymJQ&list=WL&index=12)
- Is It Time to Rewrite the Operating System in Rust? [[YouTube]](https://www.youtube.com/watch?v=HgtRAbE1nBM&list=WL&index=17&t=0s)
- InfoQ: AI, ML and Data Engineering [[YouTube]](https://www.youtube.com/playlist?list=PLndbWGuLoHeYsZk6VpCEj_SSd9IFgjJ-2)
  - Start to watch.
- Netflix: Human-centric Machine Learning Infrastructure [[InfoQ]](https://www.infoq.com/presentations/netflix-ml-infrastructure?utm_source=youtube&utm_medium=link&utm_campaign=qcontalks)
- SysML 2019: [[YouTube]](https://www.youtube.com/channel/UChutDKIa-AYyAmbT45s991g/videos)
- ScaledML 2019: David Patterson, Ion Stoica, Dawn Song and so on [[YouTube]](https://www.youtube.com/playlist?list=PLRM2gQVaW_wWXoUnSfZTxpgDmNaAS1RtG)
- ScaledML 2018: Jeff Dean, Ion Stoica, Yangqing Jia and so on [[YouTube]](https://www.youtube.com/playlist?list=PLRM2gQVaW_wW9KAxcibxdqY_TDyvmEjzm) [[Slides]](https://www.matroid.com/blog/post/slides-and-videos-from-scaledml-2018)
- A New Golden Age for Computer Architecture History, Challenges, and Opportunities. David Patterson [[YouTube]](https://www.youtube.com/watch?v=uyc_pDBJotI&t=767s)
- How to Have a Bad Career. David Patterson (I am a big fan) [[YouTube]](https://www.youtube.com/watch?v=Rn1w4MRHIhc)
- SysML 18: Perspectives and Challenges. Michael Jordan [[YouTube]](https://www.youtube.com/watch?v=4inIBmY8dQI&t=26s)
- SysML 18: Systems and Machine Learning Symbiosis. Jeff Dean [[YouTube]](https://www.youtube.com/watch?v=Nj6uxDki6-0)

## Course

- Topics in Networks: Machine Learning for Networking and Systems, Autumn 2019 [[Course Website]](https://people.cs.uchicago.edu/~junchenj/34702-fall19/syllabus.html)
- CS6465: Emerging Cloud Technologies and Systems Challenges [[Cornell]](http://www.cs.cornell.edu/courses/cs6465/2019fa/)
- CS294: AI For Systems and Systems For AI. [[UC Berkeley Spring]](https://github.com/ucbrise/cs294-ai-sys-sp19) (*Strong Recommendation*) [[Machine Learning Systems (Fall 2019)]](https://ucbrise.github.io/cs294-ai-sys-fa19/)
- CSE 599W: System for ML.  [[Chen Tianqi]](https://github.com/tqchen) [[University of Washington]](http://dlsys.cs.washington.edu/)
- Tutorial code on how to build your own Deep Learning System in 2k Lines [[GitHub]](https://github.com/tqchen/tinyflow)
- CSE 291F: Advanced Data Analytics and ML Systems. [[UCSD]](http://cseweb.ucsd.edu/classes/wi19/cse291-f/)
- CSci 8980: Machine Learning in Computer Systems [[University of Minnesota, Twin Cities]](http://www-users.cselabs.umn.edu/classes/Spring-2019/csci8980/)
- Mu Li (MxNet, Parameter Server): Introduction to Deep Learning [[Best DL Course I think]](https://courses.d2l.ai/berkeley-stat-157/index.html)  [[Book]](https://www.d2l.ai/)

## Blog

- Parallelizing across multiple CPU/GPUs to speed up deep learning inference at the edge [[Amazon Blog]](https://aws.amazon.com/blogs/machine-learning/parallelizing-across-multiple-cpu-gpus-to-speed-up-deep-learning-inference-at-the-edge/)
- Building Robust Production-Ready Deep Learning Vision Models in Minutes [[Blog]](https://medium.com/google-developer-experts/building-robust-production-ready-deep-learning-vision-models-in-minutes-acd716f6450a)
- Deploy Machine Learning Models with Keras, FastAPI, Redis and Docker [[Blog]](https://medium.com/@shane.soh/deploy-machine-learning-models-with-keras-fastapi-redis-and-docker-4940df614ece)
- How to Deploy a Machine Learning Model -- Creating a production-ready API using FastAPI + Uvicorn [[Blog]](https://towardsdatascience.com/how-to-deploy-a-machine-learning-model-dc51200fe8cf) [[GitHub]](https://github.com/MaartenGr/ML-API)
- Deploying a Machine Learning Model as a REST API [[Blog]](https://towardsdatascience.com/deploying-a-machine-learning-model-as-a-rest-api-4a03b865c166)
- Continuous Delivery for Machine Learning [[Blog]](https://martinfowler.com/articles/cd4ml.html)
- Kubernetes CheatSheets In A4 [[GitHub]](https://github.com/HuaizhengZhang/cheatsheet-kubernetes-A4)
- A Gentle Introduction to Kubernetes [[Blog]](https://medium.com/faun/a-gentle-introduction-to-kubernetes-4961e443ba26)
- Train and Deploy Machine Learning Model With Web Interface - Docker, PyTorch & Flask [[GitHub]](https://github.com/imadelh/ML-web-app)
- Learning Kubernetes, The Chinese Taoist Way [[GitHub]](https://github.com/caicloud/kube-ladder)
- Data pipelines, Luigi, Airflow: everything you need to know [[Blog]](https://towardsdatascience.com/data-pipelines-luigi-airflow-everything-you-need-to-know-18dc741449b7)
- The Deep Learning Toolset — An Overview [[Blog]](https://medium.com/luminovo/the-deep-learning-toolset-an-overview-b71756016c06)
- Summary of CSE 599W: Systems for ML [[Chinese Blog]](http://jcf94.com/2018/10/04/2018-10-04-cse559w/)
- Polyaxon, Argo and Seldon for Model Training, Package and Deployment in Kubernetes [[Blog]](https://medium.com/analytics-vidhya/polyaxon-argo-and-seldon-for-model-training-package-and-deployment-in-kubernetes-fa089ba7d60b)
- Overview of the different approaches to putting Machine Learning (ML) models in production [[Blog]](https://medium.com/analytics-and-data/overview-of-the-different-approaches-to-putting-machinelearning-ml-models-in-production-c699b34abf86)
- Being a Data Scientist does not make you a Software Engineer [[Part1]](https://towardsdatascience.com/being-a-data-scientist-does-not-make-you-a-software-engineer-c64081526372)
  Architecting a Machine Learning Pipeline [[Part2]](https://towardsdatascience.com/architecting-a-machine-learning-pipeline-a847f094d1c7)
- Model Serving in PyTorch [[Blog]](https://pytorch.org/blog/model-serving-in-pyorch/)
- Machine learning in Netflix [[Medium]](https://medium.com/@NetflixTechBlog)
- SciPy Conference Materials (slides, repo) [[GitHub]](https://github.com/deniederhut/Slides-SciPyConf-2018)
- 继Spark之后，UC Berkeley 推出新一代AI计算引擎——Ray [[Blog]](http://www.qtmuniao.com/2019/04/06/ray/)
- 了解/从事机器学习/深度学习系统相关的研究需要什么样的知识结构？ [[Zhihu]](https://www.zhihu.com/question/315611053/answer/623529977)
- Learn Kubernetes in Under 3 Hours: A Detailed Guide to Orchestrating Containers [[Blog]](https://www.freecodecamp.org/news/learn-kubernetes-in-under-3-hours-a-detailed-guide-to-orchestrating-containers-114ff420e882/) [[GitHub]](https://github.com/rinormaloku/k8s-mastery)
- data-engineer-roadmap: Learning from multiple companies in Silicon Valley. Netflix, Facebook, Google, Startups [[GitHub]](https://github.com/hasbrain/data-engineer-roadmap)
- TensorFlow Serving + Docker + Tornado机器学习模型生产级快速部署 [[Blog]](https://zhuanlan.zhihu.com/p/52096200?utm_source=wechat_session&utm_medium=social&utm_oi=38612796178432)
- Deploying a Machine Learning Model as a REST API [[Blog]](https://towardsdatascience.com/deploying-a-machine-learning-model-as-a-rest-api-4a03b865c166)

## Userful Tools

#### Profile
- Collective Knowledge repository to automate MLPerf - a broad ML benchmark suite for measuring performance of ML software frameworks, ML hardware accelerators, and ML cloud platforms [[GitHub]](https://github.com/ctuning/ck-mlperf)
- NetworKit is a growing open-source toolkit for large-scale network analysis. [[GitHub]](https://github.com/kit-parco/networkit)
- gpu-sentry: Flask-based package for monitoring utilisation of nVidia GPUs. [[GitHub]](https://github.com/jacenkow/gpu-sentry)
- anderskm/gputil: A Python module for getting the GPU status from NVIDA GPUs using nvidia-smi programmically in Python [[GitHub]](https://github.com/anderskm/gputil)
- Pytorch-Memory-Utils: detect your GPU memory during training with Pytorch. [[GitHub]](https://github.com/Oldpan/Pytorch-Memory-Utils)
- torchstat: a lightweight neural network analyzer based on PyTorch. [[GitHub]](https://github.com/Swall0w/torchstat)
- NVIDIA GPU Monitoring Tools [[GitHub]](https://github.com/NVIDIA/gpu-monitoring-tools)
- PyTorch/cpuinfo: cpuinfo is a library to detect essential for performance optimization information about host CPU. [[GitHub]](https://github.com/pytorch/cpuinfo)
- Popular Network memory consumption and FLOP counts [[GitHub]](https://github.com/albanie/convnet-burden)
- Intel® VTune™ Amplifier [[Website]](https://software.intel.com/en-us/vtune)
  - Stop guessing why software is slow. Advanced sampling and profiling techniques quickly analyze your code, isolate issues, and deliver insights for optimizing performance on modern processors
- Pyflame: A Ptracing Profiler For Python [[GitHub]](https://github.com/uber/pyflame)

#### Others
- Facebook AI Performance Evaluation Platform [[GitHub]](https://github.com/facebook/FAI-PEP)
- Netron: Visualizer for deep learning and machine learning models [[GitHub]](https://github.com/lutzroeder/netron)
- Facebook/FBGEMM: FBGEMM (Facebook GEneral Matrix Multiplication) is a low-precision, high-performance matrix-matrix multiplications and convolution library for server-side inference. [[GitHub]](https://github.com/pytorch/FBGEMM)
- Dslabs: Distributed Systems Labs and Framework for UW system course [[GitHub]](https://github.com/emichael/dslabs)
- Machine Learning Model Zoo [[Website]](https://modelzoo.co/)
- Faiss: A library for efficient similarity search and clustering of dense vectors [[GitHub]](https://github.com/facebookresearch/faiss)
- Microsoft/MMdnn: A comprehensive, cross-framework solution to convert, visualize and diagnose deep neural network models.[[GitHub]](https://github.com/Microsoft/MMdnn)
- gpushare-scheduler-extender [[GitHub]](https://github.com/HuaizhengZhang/gpushare-scheduler-extender)
  - More and more data scientists run their Nvidia GPU based inference tasks on Kubernetes. Some of these tasks can be run on the same Nvidia GPU device to increase GPU utilization. So one important challenge is how to share GPUs between the pods
- Example recipes for Kubernetes Network Policies that you can just copy paste [[GitHub]](https://github.com/ahmetb/kubernetes-network-policy-recipes)


## Project

- Machine Learning for .NET [[GitHub]](https://github.com/dotnet/machinelearning)
  - ML.NET is a cross-platform open-source machine learning framework which makes machine learning accessible to .NET developers.
  - ML.NET allows .NET developers to develop their own models and infuse custom machine learning into their applications, using .NET, even without prior expertise in developing or tuning machine learning models.
- ONNX: Open Neural Network Exchange [[GitHub]](https://github.com/onnx/onnx)
- ONNXRuntime: has an open architecture that is continually evolving to address the newest developments and challenges in AI and Deep Learning. ONNX Runtime stays up to date with the ONNX standard, supporting all ONNX releases with future compatibility and maintaining backwards compatibility with prior releases. [[GitHub]](https://github.com/microsoft/onnxruntime)
- BentoML: Machine Learning Toolkit for packaging and deploying models [[GitHub]](https://github.com/bentoml/BentoML)
- EuclidesDB: A multi-model machine learning feature embedding database [[GitHub]](https://github.com/perone/euclidesdb)
- Prefect: Perfect is a new workflow management system, designed for modern infrastructure and powered by the open-source Prefect Core workflow engine. [[GitHub]](https://github.com/PrefectHQ/prefect)
- MindsDB: MindsDB's goal is to make it very simple for developers to use the power of artificial neural networks in their projects [[GitHub]](https://github.com/mindsdb/mindsdb)
- PAI: OpenPAI is an open source platform that provides complete AI model training and resource management capabilities. [[Microsoft Project]](https://github.com/Microsoft/pai#resources)
- Bistro: Scheduling Data-Parallel Jobs Against Live Production Systems [[Facebook Project]](https://github.com/facebook/bistro)
- GNES is Generic Neural Elastic Search, a cloud-native semantic search system based on deep neural network. [[GitHub]](https://github.com/gnes-ai/gnes)



