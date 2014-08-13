  <div class="col-lg-6">
    <div class="panel panel-info">
      <div class="panel-heading">
        <i class="fa fa-desktop fa-fw"></i> 自己矿工发现的区块
      </div>
      <div class="panel-body no-padding table-responsive">
        <table class="table table-striped table-bordered table-hover">
          <thead>
            <tr>
              <th>名次</th>
              <th>矿工号</th>
              <th>区块</th>
              <th>产生的币</th>
            </tr>
          </thead>
          <tbody>
{assign var=rank value=1}
{section block $BLOCKSSOLVEDBYWORKER}
            <tr>
              <td>{$rank++}</td>
              <td>{$BLOCKSSOLVEDBYWORKER[block].finder|default:"unknown/deleted"|escape}</td>
              <td>{$BLOCKSSOLVEDBYWORKER[block].solvedblocks}</td>
              <td>{$BLOCKSSOLVEDBYWORKER[block].generatedcoins|number_format}</td>
            </tr>
{/section}
          </tbody>
        </table>
      </div>
    </div>
  </div>